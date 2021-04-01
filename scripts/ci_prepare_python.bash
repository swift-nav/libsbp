#!/usr/bin/env bash

set -ex

sudo apt-get -qq update
sudo apt-get install gcc python2.7 python2.7-dev
# https://linuxize.com/post/how-to-install-python-3-8-on-ubuntu-18-04/
sudo apt-get install software-properties-common
sudo add-apt-repository -y ppa:deadsnakes/ppa
sudo apt-get install python3.5 python3.5-dev
sudo apt-get install python3.7 python3.7-dev
sudo apt-get install python3.8 python3.8-dev
pip3 install tox wheel setuptools

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

sudo chown "$USER:$USER" "$HOME/.docker-cache"
sudo chown -R "$USER:$USER" "$HOME/.docker-cache/stack"
sudo chown -R "$USER:$USER" "$PWD"

haskell_bins="$(find "$HOME/.docker-cache/stack/work/install" -name bin)"

cp "$haskell_bins/sbp2json" .
cp "$haskell_bins/sbp2prettyjson" .
cp "$haskell_bins/json2sbp" .
cp "$haskell_bins/json2json" .
cp "$haskell_bins/sbp2nmea" .
