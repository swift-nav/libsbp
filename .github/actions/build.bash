#!/usr/bin/env bash

check_ncc() {
    command -v ncc
    if [[ "${?}" -ne 0 ]]; then
        echo "ncc is not installed. try running: 'npm i -g @vercel/ncc'"
        exit 1
    fi
}

build() {
    pushd $1
    npm i
    ncc -m build index.js --license licenses.txt
    popd
}

build_all() {
    IFS=""
    mapfile -t dirlist < <(find . -maxdepth 1 -mindepth 1 -type d -printf '%f\n')
    for dir in ${dirlist[@]}; do
        build "$dir"
    done
}

set -ex

check_ncc
build_all
