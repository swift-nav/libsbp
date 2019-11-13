#!/usr/bin/env bash

if [ "$#" -ne 1 ]; then
    echo "Skipping benchmark.sh, enable by providing a full path to Haskell SBP tools"
    exit 0
fi

set -e

TESTDATA_ROOT=$(git rev-parse --show-toplevel)/test_data
echo "Running benchmark, please wait.."

# http://mywiki.wooledge.org/BashFAQ/032
time_py=$(TIMEFORMAT="%R"; { time PYTHONPATH=$TESTDATA_ROOT/../python/ \
    python $TESTDATA_ROOT/../python/bin/sbp2json \
    < $TESTDATA_ROOT/long.sbp --mode rapidjson > $TESTDATA_ROOT/long_py.json; } 2>&1)
echo "Python" $time_py

time_hs=$(TIMEFORMAT="%R"; { time $1/sbp2json < $TESTDATA_ROOT/long.sbp > $TESTDATA_ROOT/long_hask.json; } 2>&1)
echo "Haskell" $time_hs

threshold=1.6
perf_diff=$(echo "$time_py / $time_hs" | bc -l)

if (( $(echo "$perf_diff > $threshold" | bc -l) )); then
  printf "\e[31mFAIL\e[0m: Python was %.2f times slower than Haskell. Threshold is < %.2f.\n" $perf_diff $threshold
  exit 1
fi

printf "\e[32mSUCCESS\e[0m: Python/Haskell performance ratio was %.2f. Threshold is < %.2f.\n" $perf_diff $threshold
