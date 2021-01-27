#!/usr/bin/env bash

set -ex

VERSION="$(git describe --always --tags --dirty)"

if [ "$RUNNER_OS" == "Linux" ] || [ "$RUNNER_OS" == "macOS" ]; then
    BUILD_TRIPLET="$(cc -dumpmachine)"
    ARTIFACT_NAME="sbp_tools-${VERSION}-${BUILD_TRIPLET}.tar.gz"
    EXECUTABLES=("sbp2json" "json2sbp" "json2json")
    PACKAGE_CMD="tar -czf ../../$ARTIFACT_NAME "${EXECUTABLES[@]}""
elif [ "$RUNNER_OS" == "Windows" ]; then
    BUILD_TRIPLET="$(clang -dumpmachine)"
    ARTIFACT_NAME="sbp_tools-${VERSION}-${BUILD_TRIPLET}.zip"
    EXECUTABLES=("sbp2json.exe" "json2sbp.exe" "json2json.exe")
    PACKAGE_CMD="7z a -tzip ../../$ARTIFACT_NAME "${EXECUTABLES[@]}""
else
    echo "$RUNNER_OS not supported"
    exit 1
fi

cargo build --all --release

cd target/release

strip "${EXECUTABLES[@]}"

eval "$PACKAGE_CMD"

echo "::set-output name=artifact_name::$ARTIFACT_NAME"
