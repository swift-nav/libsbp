#!/usr/bin/env python3

import os
import sys
import gzip
import json
import subprocess

# If the ratio is off from expected by more than this percentage
SLUSH_PERCENTAGE = 0.25

# How much faster Rust should be than other implementations
RATIOS_SBP2JSON = {
    "haskell": 2.19,
    "python": 24.96,
}

RATIOS_JSON2SBP = {
    "haskell": 2.05,
}

RATIOS_JSON2JSON = {
    "haskell": 2.78,
}

FAILED = [False]


def maybe_via_docker(pwd, image, cmd):
    if not os.environ.get('VIA_DOCKER'):
        return cmd
    return [
        'docker', 'run', '-i',
        '--cpus=2', '--memory=1g',
        '--rm', '-v', f'{pwd}:/work',
        image
    ] + cmd


def compare_ratio(expected, actual):
    diff = abs(expected - actual)
    percentage = diff / expected
    return percentage <= SLUSH_PERCENTAGE


def get_bench_mean(bench, lang):
    for result in bench["results"]:
        if result["parameter"] == lang:
            return float(result["mean"])


def validate_thresholds(binary, thresholds, means, target):
    for lang in thresholds:
        threshold = thresholds[lang]
        ratio = means[lang] / target
        if not compare_ratio(threshold, ratio):
            sys.stderr.write(
                f"\nERROR: {binary} speed threshold failed for {lang}, expected: {threshold}, actual: {ratio}\n\n")
            sys.stderr.flush()
            FAILED[0] = True


def main():

    if not os.environ.get("BENCHMARK_SKIP_SBP2JSON"):
        subprocess.run(
            ['hyperfine', '--warmup', '3', '--show-output',
             '--export-json', 'benchmark_sbp2json.json',
             '-L', 'lang', 'rust,python,haskell',
             './test_data/benchmark/sbp2json_{lang}.py'],
            check=True)
        print()

    bench_sbp2json = json.load(open('benchmark_sbp2json.json'))
    sbp2json_rust_mean = get_bench_mean(bench_sbp2json, "rust")
    means_sbp2json = {
        "haskell": get_bench_mean(bench_sbp2json, "haskell"),
        "python": get_bench_mean(bench_sbp2json, "python"),
    }

    validate_thresholds("sbp2json", RATIOS_SBP2JSON, means_sbp2json, sbp2json_rust_mean)

    benchmark_input_json2sbp_gz = open("test_data/benchmark.json2sbp.gz", "rb")
    json_data = gzip.decompress(benchmark_input_json2sbp_gz.read())

    with open("test_data/benchmark.json2sbp", "wb") as benchmark_input_json2sbp:
        benchmark_input_json2sbp.write(json_data)

    if not os.environ.get("BENCHMARK_SKIP_JSON2SBP"):
        subprocess.run(
            ['hyperfine', '--warmup', '3', '--show-output',
             '--export-json', 'benchmark_json2sbp.json',
             '-L', 'lang', 'rust,haskell',
             './test_data/benchmark/json2sbp_{lang}.py'],
            check=True)
        print()

    bench_json2sbp = json.load(open('benchmark_json2sbp.json'))

    means_json2sbp = {
        "haskell": get_bench_mean(bench_json2sbp, "haskell"),
    }

    json2sbp_rust_mean = get_bench_mean(bench_json2sbp, "rust")

    validate_thresholds("json2sbp", RATIOS_JSON2SBP, means_json2sbp, json2sbp_rust_mean)

    benchmark_input_json2json_gz = open("test_data/benchmark.json2json.gz", "rb")
    json_data = gzip.decompress(benchmark_input_json2json_gz.read())

    with open("test_data/benchmark.json2json", "wb") as benchmark_input_json2json:
        benchmark_input_json2json.write(json_data)

    subprocess.run(
        ['hyperfine', '--warmup', '3', '--show-output',
         '--export-json', 'benchmark_json2json.json',
         '-L', 'lang', 'rust,haskell',
         './test_data/benchmark/json2json_{lang}.py'],
        check=True)
    print()

    bench_json2json = json.load(open('benchmark_json2json.json'))

    means_json2json = {
        "haskell": get_bench_mean(bench_json2json, "haskell"),
    }

    json2json_rust_mean = get_bench_mean(bench_json2json, "rust")

    validate_thresholds("json2json", RATIOS_JSON2JSON, means_json2json, json2json_rust_mean)

    if FAILED[0]:
        sys.exit(1)


if __name__ == '__main__':
    main()
