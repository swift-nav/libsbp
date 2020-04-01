#!/usr/bin/env bash

set -ex

pushd haskell

docker build --tag haskell-sbp2json .

docker run \
  -v "$PWD:/work" \
  -v "$HOME/.docker-cache/stack/work:/work/.stack-work" \
  -v "$HOME/.docker-cache/stack/home:/root/.stack" \
  --rm \
  --name haskell-sbp2json-run \
  haskell-sbp2json \
  stack build -j4 --allow-different-user

sudo chown    "$USER:$USER" "$HOME/.docker-cache"
sudo chown -R "$USER:$USER" "$HOME/.docker-cache/stack"
sudo chown -R "$USER:$USER" "$PWD"

haskell_bins="$(find "$HOME/.docker-cache/stack/work/install" -name bin)"

cp "$haskell_bins/sbp2json" .
cp "$haskell_bins/sbp2prettyjson" .
cp "$haskell_bins/json2sbp" .
cp "$haskell_bins/json2json" .

tar -C "$haskell_bins" -czf sbp_linux_tools.tar.gz \
    sbp2json \
    sbp2prettyjson \
    sbp2yaml \
    json2sbp \
    json2json

VERSION=$(git describe --always --tags --dirty)
BUILD_TRIPLET=$(cc -dumpmachine)

mv sbp_linux_tools.tar.gz "sbp_tools_haskell-${VERSION}-${BUILD_TRIPLET}.tar.gz"
ls -l

popd

make test-python
