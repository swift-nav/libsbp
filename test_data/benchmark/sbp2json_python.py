#!/usr/bin/env python3

import os
import subprocess

PWD = os.getcwd()

TESTDATA_ROOT = os.path.join(PWD, "test_data")
os.environ['PYTHONPATH'] = os.path.join(PWD, "python")

LONG_SBP = os.path.join(TESTDATA_ROOT, "benchmark.sbp")

subprocess.run(
    ['python3', '-m', "sbp2json", '--mode', 'rapidjson'],
    stdin=open(LONG_SBP, 'rb'),
    stdout=subprocess.DEVNULL,
    check=True)
