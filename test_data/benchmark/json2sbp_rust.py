#!/usr/bin/env python3

import os
import subprocess

PWD = os.getcwd()
TESTDATA_ROOT = os.path.join(PWD, "test_data")
LONG_SBP = os.path.join(TESTDATA_ROOT, "benchmark.json2sbp")

subprocess.run(
    ['./rust/bin/json2sbp'],
    stdin=open(LONG_SBP, 'rb'),
    stdout=subprocess.DEVNULL,
    check=True)
