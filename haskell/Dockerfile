FROM debian:stretch-slim

RUN \
  apt-get update && \
  apt-get install curl make ca-certificates xz-utils -y --no-install-recommends && \
  curl -sSL https://get.haskellstack.org/ | sh

WORKDIR /work
