#!/usr/bin/env bash

sed -e "s@^.*TODO.*replace.*sbp.*\$@version = \"$NEW_VERSION\"@" Cargo.toml > Cargo.toml.new
mv Cargo.toml.new Cargo.toml
