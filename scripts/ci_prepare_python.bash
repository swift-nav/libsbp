#!/usr/bin/env bash
# This script prepares the environment for Python use in ubuntu 24.04 runners in CI.

set -ex

sudo apt-get -qq update

sudo apt-get install -y software-properties-common
sudo add-apt-repository -y ppa:deadsnakes/ppa

sudo apt-get -qq update

# Install Python 3.7, 3.9, 3.10, and the default Python 3 version
# (Note: distutils is deprecated for default python on Ubuntu 24.04)
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
    python3.7 python3.7-dev python3.7-distutils \
    python3.9 python3.9-dev python3.9-distutils \
    python3.10 python3.10-dev python3.10-distutils \
    python3 python3-dev python3-pip \
    musl-tools \
    tox dpkg-dev wget

# --break-system-packages is only a temporary workaround for the workflows to run
# Long term solution would be to create a dedicated virtual environments for each Python version
# using uv
pip3 install --break-system-packages wheel setuptools
