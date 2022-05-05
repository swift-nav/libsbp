#!/bin/bash

python scripts/spec_validator.py $1 $2 2>&1 | tee /tmp/log.txt

ERROR=$(cat /tmp/log.txt | grep RuntimeError)

if [ ! -z "$ERROR" ]; then
    exit 1
fi

WARN=$(cat /tmp/log.txt | grep WARNING)

if [ ! -z "$WARN" ]; then
    FILE=$(echo $WARN | awk '{print $2}')
    echo "::warning file=spec/yaml/swiftnav/sbp/${FILE}::$WARN"
fi
