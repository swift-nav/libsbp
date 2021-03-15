#!/usr/bin/env bash

set -ex

sudo apt-get -qq update
sudo apt-get install gcc python2.7 python2.7-dev
# https://linuxize.com/post/how-to-install-python-3-8-on-ubuntu-18-04/
sudo apt-get install software-properties-common
sudo add-apt-repository -y ppa:deadsnakes/ppa
sudo apt-get install python3.5 python3.5-dev
sudo apt-get install python3.8 python3.8-dev
pip3 install tox wheel setuptools
