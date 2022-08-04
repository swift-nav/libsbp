#!/usr/bin/env bash

set -ex

VERSION="$(git describe --always --tags --dirty)"

if [ "$RUNNER_OS" == "macOS" ]; then
    ARTIFACT_NAME="sbp_tools-${VERSION}-x86_64-apple-darwin.zip"
    EXECUTABLES=("sbp2json" "json2sbp" "json2json")
    PACKAGE_CMD="zip ../../../$ARTIFACT_NAME ${EXECUTABLES[*]}"
elif [ "$RUNNER_OS" == "Linux" ]; then
    ARTIFACT_NAME="sbp_tools-${VERSION}-x86_64-unknown-linux-musl.zip"
    EXECUTABLES=("sbp2json" "json2sbp" "json2json")
    PACKAGE_CMD="zip ../../../$ARTIFACT_NAME ${EXECUTABLES[*]}"
elif [ "$RUNNER_OS" == "Windows" ]; then
    ARTIFACT_NAME="sbp_tools-${VERSION}-x86_64-pc-windows-msvc.zip"
    EXECUTABLES=("sbp2json.exe" "json2sbp.exe" "json2json.exe")
    PACKAGE_CMD="7z a -tzip ../../../$ARTIFACT_NAME ${EXECUTABLES[*]}"
else
    echo "$RUNNER_OS not supported"
    exit 1
fi

cargo build --no-default-features -p sbp
cargo build --no-default-features -p sbp --features serde
cargo build --no-default-features -p sbp --features json
cargo build --no-default-features -p sbp --features async
cargo build --no-default-features -p sbp --features link
cargo build --no-default-features -p sbp --features float_roundtrip

if [ "$RUNNER_OS" == "Linux" ]; then
  cargo build --all --release --target=x86_64-unknown-linux-musl
  cd target/x86_64-unknown-linux-musl/release
elif [ "$RUNNER_OS" == "Windows" ]; then
  cargo build --all --release --target=x86_64-pc-windows-msvc
  cd target/x86_64-pc-windows-msvc/release
elif [ "$RUNNER_OS" == "macOS" ]; then
  cargo build --all --release --target=x86_64-apple-darwin
  cd target/x86_64-apple-darwin/release
else
  cargo build --all --release
  cd target/release
fi

strip "${EXECUTABLES[@]}"

eval "$PACKAGE_CMD"

echo "::set-output name=artifact_name::$ARTIFACT_NAME"
