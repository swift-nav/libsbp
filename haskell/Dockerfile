FROM debian:stretch

ADD . /app
WORKDIR /app

RUN \
  apt-get update && \
  apt-get install curl make ca-certificates xz-utils -y --no-install-recommends && \
  curl -sSL https://get.haskellstack.org/ | sh && \
  stack build

CMD \
  tar -C $(find .stack-work/install -name bin) -cf - \
    sbp2json \
    sbp2prettyjson \
    sbp2yaml \
    json2sbp \
    json2json
