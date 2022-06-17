#!/usr/bin/env bash

set -ex

sudo apt-get -qq update

sudo apt-get install -y software-properties-common
sudo add-apt-repository -y ppa:deadsnakes/ppa

sudo apt-get -qq update

sudo apt-get install -y \
    build-essential \
    zlib1g-dev \
    libbz2-dev \
    libssl-dev \
    libreadline-dev \
    libncurses5-dev \
    libsqlite3-dev \
    libgdbm-dev \
    libdb-dev \
    libexpat-dev \
    libpcap-dev \
    liblzma-dev \
    libpcre3-dev \
    python3.6 python3.6-dev python3.6-distutils \
    python3.7 python3.7-dev python3.7-distutils \
    python3 python3-dev python3-distutils \
    python3.9 python3.9-dev python3.9-distutils \
    python3.10 python3.10-dev python3.10-distutils \
    musl-tools \
    tox dpkg-dev wget

pip3 install wheel setuptools
