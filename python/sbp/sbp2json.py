from __future__ import print_function

import sys

import json

from sbp.client import Handler, Framer

DEFAULT_JSON = 'rapidjson'
JSON_CHOICES = ['json', 'rapidjson']
try:
    import rapidjson
except ImportError:
    DEFAULT_JSON = 'json'
    JSON_CHOICES = ['json']

try:
    memoryview
except NameError:
    memoryview = lambda x: x


def base_cl_options():
    import argparse
    parser = argparse.ArgumentParser(prog="sbp2json", description="Swift Navigation SBP to JSON parser")
    parser.add_argument('--mode', type=str, choices=JSON_CHOICES, default=DEFAULT_JSON,
                        help="the JSON serialization library to use, default: {}".format(DEFAULT_JSON))
    parser.add_argument('--include', nargs="+", type=int, default=[],
                        help="list of SBP message IDs to include, empty means all")
    parser.add_argument('file', nargs='?', metavar='FILE', type=argparse.FileType('rb'),
                        default=sys.stdin, help="the input file, stdin by default")

    group_json = parser.add_argument_group('json specific arguments')
    group_json.add_argument(
        "--sort-keys",
        action="store_true",
        help="Sort JSON log elements by keys")

    return parser


def get_args():
    """
    Get and parse arguments.
    """
    parser = base_cl_options()
    args = parser.parse_args()

    return args


def dump(args, res):
    if 'json' == args.mode:
        sys.stdout.write(json.dumps(res.to_json_dict(),
                                    allow_nan=False,
                                    sort_keys=args.sort_keys,
                                    separators=(',', ':')))
    elif 'rapidjson' == args.mode:
        sys.stdout.write(rapidjson.dumps(res.to_json_dict()))
    sys.stdout.write("\n")


def module_main():
    if args := get_args():
        with Handler(Framer(args.file.read, None, verbose=True)) as source:
            try:
                it = source.__iter__()
                while msg_meta := next(it, None):
                    dump(args, msg_meta[0])
            except KeyboardInterrupt:
                pass
