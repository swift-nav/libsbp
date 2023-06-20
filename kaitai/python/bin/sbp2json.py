#!/usr/bin/env python3
#
# implementation of sbp2json using Kaitai Struct parser

from kaitai_sbp.parse_utils import iter_messages, serialise
import rapidjson
import sys


def sbp2json(infile):
    for msg in iter_messages(f):
        print(rapidjson.dumps(msg, default=serialise))


if __name__ == '__main__':
    if len(sys.argv) == 1:
        with open(0, 'rb') as f:
            sbp2json(f)
    else:
        for filename in sys.argv[1:]:
            with open(filename, 'rb') as f:
                sbp2json(f)
