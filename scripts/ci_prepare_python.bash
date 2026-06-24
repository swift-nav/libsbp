#!/usr/bin/env bash
# This script prepares the environment for Python use in CI.
# Python interpreters are provided by actions/setup-python in the workflow;
# here we only install the system build dependencies and tox.

set -ex

sudo apt-get -qq update

# System libraries needed to build native extensions / source dists.
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
    musl-tools \
    dpkg-dev wget

pip3 install wheel setuptools tox
