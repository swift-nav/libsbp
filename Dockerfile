# Copyright (C) 2020 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

# This describes an image that should be able to generate libsbp bindings.
# See the README.md for instructions on how to use it.

FROM ubuntu:bionic

ARG DEBIAN_FRONTEND=noninteractive

ENV NODE_VERSION=v12.22.0

ENV RUSTUP_HOME=/rust
ENV CARGO_HOME=/cargo

ENV PATH=/usr/lib/ccache:/cargo/bin:/rust/bin:${PATH}

RUN \
     apt-get update \
  && apt-get install -y \
      git \
      sudo \
      software-properties-common \
      apt-utils \
      wget \
      curl \
      build-essential \
      pandoc \
      llvm \
      gradle \
      texlive-science \
      texlive-fonts-extra \
      check \
      ccache \
      pkg-config \
      doxygen \
      graphviz \
      texlive-latex-base \
      imagemagick \
      libudev-dev \
      uuid-dev \
      libgmp-dev \
      zlib1g-dev \
      clang-format-6.0

RUN add-apt-repository ppa:deadsnakes/ppa \
  && apt-get update \
  && apt-get install -y \
      python-pip \
      python3-pip \
      python3.5-dev \
      python3.6-dev \
      python3.7-dev \
      python3.8-dev \
      python3.9-dev python3.9-dist \
  && pip3 install tox \
  && pip install sphinx \
  && curl https://sh.rustup.rs -sSf | sh -s -- -y --default-toolchain stable --no-modify-path \
  && curl -sSL https://get.haskellstack.org/ | sh \
  && rm -rf /var/lib/apt/lists/*

RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null \
  && add-apt-repository 'deb https://apt.kitware.com/ubuntu/ bionic main' \ 
  && apt-get update \
  && apt-get install -y \
    cmake

ENV NVM_DIR /opt/nvm

RUN mkdir -p $NVM_DIR \
  && curl -sL https://raw.githubusercontent.com/creationix/nvm/v0.38.0/install.sh | bash \
  && . $NVM_DIR/nvm.sh \
  && nvm install $NODE_VERSION

ENV NODE_PATH $NVM_DIR/versions/node/$NODE_VERSION/lib/node_modules
ENV PATH      $NVM_DIR/versions/node/$NODE_VERSION/bin:$PATH

RUN npm install npm@latest mocha quicktype -g

# Add a "dockerdev" user with sudo capabilities
# 1000 is the first user ID issued on Ubuntu; might
# be different for Mac users. Might need to add more.
RUN useradd -u 1000 -ms /bin/bash -G sudo dockerdev \
    && echo '%sudo ALL=(ALL) NOPASSWD:ALL' >>/etc/sudoers \
    && find $NVM_DIR -exec chmod a+rw {} \; \
    && find $RUSTUP_HOME -exec chmod a+rw {} \; \
    && find $CARGO_HOME -exec chmod a+rw {} \;

WORKDIR /mnt/workspace
USER dockerdev

RUN stack install --resolver lts-10.10 sbp

# vim: ft=dockerfile
