# Copyright (C) 2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
"""
Generate missing test cases automatically.
"""

import argparse
import collections
import datetime
import os.path
import sys

from sbp.client.drivers.network_drivers import TCPDriver
from sbp.client import Handler, Framer
from sbp.table import _SBP_TABLE
from sbp.utils import walk_json_dict, exclude_fields

from sbpg.test_structs import PackageTestSpecification, TestSpecification

HERE = os.path.dirname(__file__)
PYTHON_ROOT = os.path.abspath(os.path.join(HERE, "..", "python"))
sys.path.insert(0, PYTHON_ROOT)

from tests.sbp.test_messages import CASES, ROOTPATH  # noqa
from tests.sbp.utils import load_test_package, assert_package  # noqa


def load_test_cases():
    tests = {}
    for case in CASES:
        filename = ROOTPATH + "/" + case
        try:
            pkg = load_test_package(filename)
        except Exception as e:
            print(e)
            continue
        for i, test_case_data in enumerate(pkg["tests"]):
            tests[(case, i)] = test_case_data
    return tests


def msg_reducer(msg):
    return {
        "fields": walk_json_dict(exclude_fields(msg)),
        "module": msg.__class__.__module__,
        "name": msg.__class__.__name__,
    }


def write_test(msg, test_set_name="swiftnav"):
    module = msg.__class__.__module__
    name = msg.__class__.__name__
    path_parts = (
        [ROOTPATH, test_set_name] + module.split(".") + ["test_{}.yaml".format(name)]
    )
    filename = os.path.join(*path_parts)
    test_msg_data = msg_reducer(msg)
    test_data = TestSpecification.from_msg(msg, test_msg_data)
    now_str = datetime.datetime.now().isoformat(" ")
    test_package = PackageTestSpecification(
        package=module,
        description="Unit tests for {}.{} {}".format(test_set_name, module, name),
        generated_on=now_str,
        tests=[test_data],
    )
    print("Writing {} ...".format(filename))
    test_package.write(filename, exists_ok=True)
    print("Wrote {}".format(filename))
    assert_package(filename)


def main():
    parser = argparse.ArgumentParser(description="Swift Navigation SBP Test Generator.")
    parser.add_argument(
        "-a",
        "--host",
        default="localhost",
        help="specify the host address. e.g. piksi-relay-bb9f2b10e53143f4a816a11884e679cf.ce.swiftnav.com",
    )
    parser.add_argument("-p", "--port", default=55555, help="specify the port to use.")
    args = parser.parse_args()

    test_cases = load_test_cases()
    msg_class_tests = collections.defaultdict(list)
    for test_case_data in test_cases.values():
        key = (test_case_data["msg"]["module"], test_case_data["msg"]["name"])
        msg_class_tests[key].append(test_case_data)

    # Check uniqueness of the msg classes
    msg_class_tests_2 = {}
    for (module, name), tests in msg_class_tests.items():
        assert name not in msg_class_tests_2
        msg_class_tests_2[name] = tests

    classes_without_tests = {}
    req_resp_missing = 0
    deprecated_missing = 0
    for msg_type, cls in _SBP_TABLE.items():
        cls_name = cls.__name__
        if cls_name not in msg_class_tests_2:
            is_real_message = hasattr(cls, "_parser")
            if is_real_message:
                if cls_name.endswith("Dep") or cls_name[-4:-1] == "Dep":
                    deprecated_missing += 1
                if cls_name.endswith("Req") or cls_name.endswith("Resp"):
                    req_resp_missing += 1
                print("Missing {}: {}".format(msg_type, cls_name))
                classes_without_tests[cls_name] = cls

    print(
        "Total missing: {} ({} Req/Resp; {} Dep.)".format(
            len(classes_without_tests), req_resp_missing, deprecated_missing
        )
    )
    new_test_data = {}

    with TCPDriver(args.host, args.port) as driver:
        with Handler(Framer(driver.read, None, verbose=True)) as source:
            try:
                for msg, metadata in source:
                    assert msg.__class__ in _SBP_TABLE.values()
                    if msg.__class__ in classes_without_tests.values():
                        print("Found missing test data: {!r}".format(msg))
                        cls_name = msg.__class__.__name__
                        new_test_data[cls_name] = msg
                        try:
                            write_test(msg)
                            del classes_without_tests[cls_name]
                        except Exception as e:
                            print("Failed creating test for {}: {}".format(cls_name, e))
                            raise

            except KeyboardInterrupt:
                pass


if __name__ == "__main__":
    main()
