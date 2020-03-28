FROM rust:slim-stretch

ARG DEBIAN_FRONTEND=noninterative

ARG SCCACHE_VER=0.2.12
ARG SCCACHE_FILE=${SCCACHE_VER}/sccache-${SCCACHE_VER}-x86_64-unknown-linux-musl.tar.gz
ARG SCCACHE_URL=https://github.com/mozilla/sccache/releases/download/${SCCACHE_FILE}

ENV SCCACHE_CACHE_SIZE=100G
ENV SCCACHE_DIR=/opt/sccache

RUN mkdir -p $SCCACHE_DIR

RUN \
      apt-get update \
   && apt-get install -y libssl-dev pkg-config curl \
   && curl -sSL -o /tmp/sccache.tgz "${SCCACHE_URL}" \
   && mkdir /tmp/sccache \
   && tar --strip-components=1 -C /tmp/sccache -xzf /tmp/sccache.tgz \
   && mv /tmp/sccache/sccache /usr/local/bin \
   && chmod +x /usr/local/bin/sccache \
   && rustup component add rustfmt \
   && rustup component add clippy \
   && rm -rf /var/lib/apt/lists/* \
   && rm -rf /tmp/sccache /tmp/sccache.tgz

ENV RUSTC_WRAPPER=/usr/local/bin/sccache

ADD . /work
WORKDIR /work

RUN cargo install --path .

CMD \
  tar -C $(find ~/.cargo -name bin) -cf - \
    sbp2json \
    json2sbp \
    json2json
