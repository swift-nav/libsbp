#!/usr/bin/env python3

import os
import subprocess

PWD = os.getcwd()
TESTDATA_ROOT = os.path.join(PWD, "test_data")
LONG_SBP = os.path.join(TESTDATA_ROOT, "long.sbp")

subprocess.run(
    ['./rust/bin/sbp2json'],
    stdin=open(LONG_SBP, 'rb'),
    stdout=subprocess.DEVNULL)
