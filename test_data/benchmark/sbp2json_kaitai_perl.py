#!/usr/bin/env python3

import os
import subprocess

from benchmark_main import maybe_via_docker

PWD = os.getcwd()

TESTDATA_ROOT = os.path.join(PWD, "test_data")

LONG_SBP = os.path.join(TESTDATA_ROOT, "benchmark.sbp")

CMD = ['perl', 'kaitai/perl/bin/sbp2json.pl']

subprocess.run(
    maybe_via_docker(PWD, "python-sbp2json", CMD),
    stdin=open(LONG_SBP, 'rb'),
    stdout=subprocess.DEVNULL,
    check=True)
