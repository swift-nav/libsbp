#!/usr/bin/env bash
if [ "$#" -ne 1 ]; then
    echo "Skipping format-test.sh, enable by providing a full path to Haskell SBP tools"
    exit 0
fi

set -e

TESTDATA_ROOT=$(git rev-parse --show-toplevel)/test_data
INPUT_SHORT=$TESTDATA_ROOT/short.sbp
OUTPUT_SHORT_HS=$TESTDATA_ROOT/short_hask_pretty.json
OUTPUT_SHORT_PY=$TESTDATA_ROOT/short_py_pretty.json

INPUT_LONG=$TESTDATA_ROOT/long.sbp
OUTPUT_LONG_HS=$TESTDATA_ROOT/long_hask_pretty.json
OUTPUT_LONG_PY=$TESTDATA_ROOT/long_py_pretty.json

PYTHONPATH=$TESTDATA_ROOT/../python/ \
    python $TESTDATA_ROOT/../python/bin/sbp2json \
    < $INPUT_SHORT --mode json --sort-keys --judicious-rounding > $OUTPUT_SHORT_PY

if [ ! -f $OUTPUT_SHORT_HS ]; then
  $1/sbp2prettyjson < $INPUT_SHORT > $OUTPUT_SHORT_HS
fi

diff $OUTPUT_SHORT_HS $OUTPUT_SHORT_PY || exit 1

echo -e "Sanity check \e[32mOK\e[0m, please wait for format test.."

PYTHONPATH=$TESTDATA_ROOT/../python/ \
    python $TESTDATA_ROOT/../python/bin/sbp2json \
    < $INPUT_LONG --mode json --sort-keys --judicious-rounding > $OUTPUT_LONG_PY

if [ ! -f $OUTPUT_LONG_HS ]; then
  $1/sbp2prettyjson < $INPUT_LONG > $OUTPUT_LONG_HS
fi

diff $OUTPUT_LONG_HS $OUTPUT_LONG_PY || exit 1

echo -e "Format check \e[32mOK\e[0m"
