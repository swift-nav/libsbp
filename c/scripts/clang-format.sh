#!/usr/bin/env bash

set -e -x
# This only reformats the generated headers and tests
# as it is introduced as part of fixing the docs,
# and clang-format-6 would otherwise cause regressions
# in the Google style of hand-written code.
GENERATED_HEADERS=$(grep -l "Automatically generated" include/libsbp/*.h)
CLANG_FORMAT=clang-format-6.0
$CLANG_FORMAT -i $GENERATED_HEADERS test/*.c test/*.h test/cpp/*.cc

# clang-format-6 adds whitespace to blank lines inside comments
sed -i.bak 's/^  *$//' $GENERATED_HEADERS
rm include/libsbp/*.h.bak
