#!/usr/bin/env bash
if [ "$#" -ne 1 ]; then
    echo "Skipping format-test.sh, enable with --enable"
    exit 0
fi

set -e

TESTDATA_ROOT=$(git rev-parse --show-toplevel)/test_data

PYTHONPATH=$TESTDATA_ROOT/../python/ \
    python $TESTDATA_ROOT/../../piksi_tools/piksi_tools/sbp2json.py \
    < $TESTDATA_ROOT/short.sbp --mode json --sort-keys --float-meta > $TESTDATA_ROOT/short_py.json

$(find $TESTDATA_ROOT/../haskell/.stack-work/install -name sbp2prettyjson) \
    < $TESTDATA_ROOT/short.sbp > $TESTDATA_ROOT/short_hask.json

diff $TESTDATA_ROOT/short_hask.json $TESTDATA_ROOT/short_py.json || exit 1

echo -e "Sanity check \e[32mOK\e[0m, please wait for format test.."

PYTHONPATH=$TESTDATA_ROOT/../python/ \
    python $TESTDATA_ROOT/../../piksi_tools/piksi_tools/sbp2json.py \
    < $TESTDATA_ROOT/long.sbp --mode json --sort-keys --float-meta > $TESTDATA_ROOT/long_py.json

$(find $TESTDATA_ROOT/../haskell/.stack-work/install -name sbp2prettyjson) \
    < $TESTDATA_ROOT/long.sbp > $TESTDATA_ROOT/long_hask.json

diff $TESTDATA_ROOT/long_hask.json $TESTDATA_ROOT/long_py.json || exit 1

echo -e "Format check \e[32mOK\e[0m"
