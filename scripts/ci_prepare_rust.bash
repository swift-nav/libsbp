#!/usr/bin/env bash

set -ex

if [ "$RUNNER_OS" == "Linux" ]; then
    sudo apt-get -qq update
    sudo apt-get -qq install -y pkg-config build-essential libudev-dev musl-tools
    rustup target add x86_64-unknown-linux-musl
elif [ "$RUNNER_OS" == "macOS" ]; then
    brew install cmake
elif [ "$RUNNER_OS" == "Windows" ]; then
    echo "C:\msys64\mingw64\bin" >>"$GITHUB_PATH"
else
    echo "$RUNNER_OS not supported"
    exit 1
fi
