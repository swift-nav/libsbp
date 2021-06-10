#!/usr/bin/env bash

set -e -x
# This only reformats the generated headers and tests
# as it is introduced as part of fixing the docs,
# and clang-format-6 would otherwise cause regressions
# in the Google style of hand-written code.
GENERATED_HEADERS=$(grep -rl --include="*.h" "Automatically generated" include/libsbp/* src/)
GENERATED_C_SOURCES=$(grep -rl --include="*.c" "Automatically generated" src/)
CLANG_FORMAT=clang-format-6.0
$CLANG_FORMAT -i $GENERATED_HEADERS $GENERATED_C_SOURCES test/*.c test/*.h test/legacy/cpp/*.cc test/legacy/*.c test/auto* test/cpp/auto*

# clang-format-6 adds whitespace to blank lines inside comments
sed -i.bak 's/^  *$//' $GENERATED_HEADERS
rm ${GENERATED_HEADERS//.h/.h.bak}
