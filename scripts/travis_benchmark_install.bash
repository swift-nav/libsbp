#!/usr/bin/env bash

set -ex

HYPERFINE_RELEASE=v1.9.0
HYPERFINE_BASENAME=hyperfine-${HYPERFINE_RELEASE}-x86_64-unknown-linux-musl
HYPERFINE_URL_BASE=https://github.com/sharkdp/hyperfine/releases/download
HYPERFINE_URL=${HYPERFINE_URL_BASE}/${HYPERFINE_RELEASE}/${HYPERFINE_BASENAME}.tar.gz
HYPERFINE_BIN_PATH=${HYPERFINE_BASENAME}/hyperfine

sudo apt-get -qq update

mkdir -p ~/.local/bin
curl -sSL "${HYPERFINE_URL}" | tar -C ~/.local/bin -xvzf - --strip-components=1 "${HYPERFINE_BIN_PATH}"

export PATH="${HOME}/.local/bin:${HOME}/.cargo/bin:${PATH}"

hash -r
