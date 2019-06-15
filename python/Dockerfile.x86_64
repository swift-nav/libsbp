FROM quay.io/pypa/manylinux2010_x86_64

RUN \
     echo Setting up Linux x86 build environment... \
  && yum install -y wget \
  && wget -O /tmp/miniconda.sh https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh \
  && bash /tmp/miniconda.sh -b \
  && rm /tmp/miniconda.sh

ENV PATH=/root/miniconda3/bin:$PATH
