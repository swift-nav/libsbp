FROM balenalib/armv7hf-debian:sid-build

RUN [ "cross-build-start" ]

RUN \
     echo Setting up ARM build environment... \
  && apt-get update \
  && apt-get install wget bzip2 build-essential llvm-6.0-dev python3 \
  && update-alternatives --install /usr/bin/llvm-config llvm-config /usr/bin/llvm-config-6.0 1 \
  && wget -O /tmp/miniconda.sh https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-armv7l.sh \
  && bash /tmp/miniconda.sh -b \
  && conda install --yes pip \
  && rm /tmp/miniconda.sh

ENV PATH=/root/miniconda3/bin:$PATH
