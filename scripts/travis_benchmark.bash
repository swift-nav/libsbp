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
cp "$haskell_bins/json2sbp" .
cp "$haskell_bins/json2json" .

popd

pushd rust

docker build --tag rust-sbp2json .

cp sbp2json/Cargo.lock .

cat >Cargo.toml <<EOF
[workspace]
members = ["sbp", "sbp2json"]

[profile.release]
lto = true
codegen-units = 1
EOF

docker run \
  -v "$PWD:/work" \
  -v "$HOME/.docker-cache/cargo/work:/work/target" \
  -v "$HOME/.docker-cache/cargo/binary-cache:/usr/local/cargo/binary-cache" \
  -v "$HOME/.docker-cache/cargo/git:/usr/local/cargo/git" \
  -v "$HOME/.docker-cache/cargo/registry:/usr/local/cargo/registry" \
  -v "$HOME/.docker-cache/cargo/script-cache:/usr/local/cargo/script-cache" \
  -v "$HOME/.docker-cache/cargo/script-templates:/usr/local/cargo/script-templates" \
  --rm \
  --name rust-sbp2json-run \
  rust-sbp2json \
  cargo build --release

sudo chown    "$USER:$USER" "$HOME/.docker-cache"
sudo chown -R "$USER:$USER" "$HOME/.docker-cache/cargo"
sudo chown -R "$USER:$USER" "$PWD"

rust_bins="$HOME/.docker-cache/cargo/work/release"

mkdir bin

cp "$rust_bins/sbp2json" bin
cp "$rust_bins/json2sbp" bin
cp "$rust_bins/json2json" bin

strip "$rust_bins/sbp2json"
strip "$rust_bins/json2sbp"
strip "$rust_bins/json2json"

tar -C "$rust_bins" -czf sbp_linux_tools.tar.gz \
    sbp2json \
    json2sbp \
    json2json

VERSION="$(git describe --always --tags --dirty)"
BUILD_TRIPLET="$(cc -dumpmachine)"

mv sbp_linux_tools.tar.gz "sbp_tools-${VERSION}-${BUILD_TRIPLET}.tar.gz"
ls -l

rm Cargo.toml

popd

pushd python

if [[ -n "${VIA_DOCKER:-}" ]]; then

  docker build --tag python-sbp2json -f Dockerfile.benchmark .
else

  pip3 install -r setup_requirements.txt
  pip3 install -r requirements.txt

  python3 setup.py install
fi

popd

make benchmark
