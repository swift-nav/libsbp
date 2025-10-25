#!/usr/bin/env bash

set -e -x
# This only reformats the generated headers and tests
# as it is introduced as part of fixing the docs,
# and clang-format-11 would otherwise cause regressions
# in the Google style of hand-written code.
GENERATED_HEADERS=$(grep -rl --include="*.h" "Automatically generated" include/libsbp/* src/)
GENERATED_C_SOURCES=$(grep -rl --include="*.c" "Automatically generated" src/)
CLANG_FORMAT=clang-format-11
$CLANG_FORMAT -i $GENERATED_HEADERS $GENERATED_C_SOURCES test/*.c test/*.h test/auto* test/cpp/auto*
