#!/usr/bin/env python3

import os
import subprocess

from benchmark_main import maybe_via_docker

PWD = os.getcwd()

TESTDATA_ROOT = os.path.join(PWD, "test_data")
os.environ['PYTHONPATH'] = os.path.join(PWD, "python")

LONG_SBP = os.path.join(TESTDATA_ROOT, "benchmark.sbp")

CMD = ['python3', '-m', "sbp2json", '--mode', 'rapidjson']

subprocess.run(
    maybe_via_docker(PWD, "python-sbp2json", CMD),
    stdin=open(LONG_SBP, 'rb'),
    stdout=subprocess.DEVNULL,
    check=True)
