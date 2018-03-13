#!/usr/bin/env bash

[ "$DEBUG" == 'true' ] && set -x
set -e
set -u

# Build nanopb generator plugin
NANOPB_SRC=./nanopb
if [ ! -d $NANOPB_SRC ] || [ ! -f $NANOPB_SRC/CMakeLists.txt ]; then
    git submodule update --init
fi

PROTOC_NANOPB_PLUGIN=$NANOPB_SRC/generator/protoc-gen-nanopb
if [ ! -f $PROTOC_NANOPB_PLUGIN ]; then
    pushd $NANOPB_SRC
    cmake -Dnanopb_BUILD_RUNTIME=OFF .
    make
    popd
fi

PROTOC_EXEC=`which protoc`
PROTOC_PLUGIN_ARG=--plugin=protoc-gen-nanopb=$PROTOC_NANOPB_PLUGIN
OUTPUT_DIR=.
PROTO_PATH=..
PROTO_SRC=$PROTO_PATH/*.proto
PROTOC_NANOPB_ARGS="$PROTOC_PLUGIN_ARG --proto_path=$PROTO_PATH --nanopb_out=$OUTPUT_DIR $PROTO_SRC"
$PROTOC_EXEC $PROTOC_NANOPB_ARGS
