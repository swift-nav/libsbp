#!/usr/bin/env bash
# Runs the libsbp Python test suite on legacy interpreters (2.7, 3.7) that the
# main matrix no longer covers. Meant to run inside an official `python:2.7` /
# `python:3.7` container (see .github/workflows/python-legacy.yaml).
#
# These interpreters are EOL, so dependencies are pinned to their last
# compatible releases. sbp2json is Python 3.6+ only (uses `nonlocal`), so it is
# excluded on 2.7.

set -ex

cd "$(dirname "$0")/../python"

PYVER=$(python -c 'import sys; print("%d.%d" % sys.version_info[:2])')

ignores=""

if [ "$PYVER" = "2.7" ]; then
    # Last releases with Python 2.7 support.
    pip install --no-cache-dir --only-binary=:all: "numpy==1.16.6"
    pip install --no-cache-dir \
        "construct==2.9.52" \
        pyserial pylibftdi six pyyaml \
        "pytest==4.6.11" "pytest-cov==2.12.1" "pytest-flakes==4.0.1"
    # sbp2json is Python 3 only.
    ignores="--ignore=sbp/sbp2json.py --ignore=tests/sbp/test_sbp2json.py"
else
    # 3.7: pip resolves the newest 3.7-compatible releases.
    pip install --no-cache-dir \
        construct numpy pyserial pylibftdi six pyyaml \
        pytest pytest-cov pytest-flakes pytest-rerunfailures
fi

py.test -v sbp tests $ignores
