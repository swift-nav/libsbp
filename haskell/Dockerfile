FROM debian:bookworm-slim

RUN \
  apt-get update && \
  apt-get install curl make ca-certificates xz-utils -y --no-install-recommends && \
  rm -rf /var/lib/apt/lists/* && \
  curl -sSL https://get.haskellstack.org/ | sh

WORKDIR /work
