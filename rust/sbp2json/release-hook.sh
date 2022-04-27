#!/usr/bin/env bash

sed -i -e "s@^.*TODO.*replace.*sbp.*\$@version = \"$NEW_VERSION\"@" Cargo.toml
