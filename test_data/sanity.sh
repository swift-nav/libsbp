#!/usr/bin/env bash

set -ex

TESTDATA_ROOT=$(git rev-parse --show-toplevel)/test_data
INPUT_SHORT=$TESTDATA_ROOT/short.sbp
OUTPUT_SHORT_PY=$TESTDATA_ROOT/short_py_pretty.json

PYTHONPATH=$TESTDATA_ROOT/../python/ \
    python $TESTDATA_ROOT/../python/bin/sbp2json \
    < $INPUT_SHORT --mode json > $OUTPUT_SHORT_PY

echo -e "Sanity check \e[32mOK\e[0m"
