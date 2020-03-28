#!/usr/bin/env python3

import sys
import gzip
import json
import subprocess

SLUSH_PERCENTAGE = 0.15

THRESHOLDS_SBP2JSON = {
    "haskell": 1.86,
    "python": 1.44,
}

THRESHOLDS_JSON2SBP = {
    "haskell": 4.23,
}

THRESHOLDS_JSON2JSON = {
    "haskell": 2.81,
}

subprocess.run(
    ['hyperfine',  # '--show-output',
     '--export-json', 'benchmark_sbp2json.json',
     '-L', 'lang', 'rust,haskell,python',
     './test_data/benchmark/sbp2json_{lang}.py'],
    check=True)

def compare_threshold(expected, actual):
    diff = abs(expected - actual)
    percentage = diff / expected
    return percentage <= SLUSH_PERCENTAGE

def get_bench_mean(bench, lang):
    for result in bench["results"]:
        if result["parameter"] == lang:
            return float(result["mean"])

def validate_thresholds(thresholds, means, target):
    for lang in thresholds:
        threshold = thresholds[lang]
        ratio = means[lang] / target
        if not compare_threshold(threshold, ratio):
            sys.stderr.write(
                f"ERROR: sbp2json speed threshold failed for {lang}, expected: {threshold}, actual: {ratio}")
            sys.exit(1)

BENCH_SBP2JSON = json.load(open('benchmark_sbp2json.json'))

SBP2JSON_RUST_MEAN = get_bench_mean(BENCH_SBP2JSON, "rust")

MEANS_SBP2JSON = {
    "haskell": get_bench_mean(BENCH_SBP2JSON, "haskell"),
    "python": get_bench_mean(BENCH_SBP2JSON, "python"),
}

validate_thresholds(THRESHOLDS_SBP2JSON, MEANS_SBP2JSON, SBP2JSON_RUST_MEAN)

BENCHMARK_INPUT_JSON2SBP_GZ = open("test_data/benchmark.json2sbp.gz", "rb")
JSON_DATA = gzip.decompress(BENCHMARK_INPUT_JSON2SBP_GZ.read())

with open("test_data/benchmark.json2sbp", "wb") as BENCHMARK_INPUT_JSON2SBP:
    BENCHMARK_INPUT_JSON2SBP.write(JSON_DATA)

subprocess.run(
    ['hyperfine',  # '--show-output',
     '--export-json', 'benchmark_json2sbp.json',
     '-L', 'lang', 'rust,haskell',
     './test_data/benchmark/json2sbp_{lang}.py'],
    check=True)

BENCH_JSON2SBP = json.load(open('benchmark_json2sbp.json'))

MEANS_JSON2SBP = {
    "haskell": get_bench_mean(BENCH_JSON2SBP, "haskell"),
}

JSON2SBP_RUST_MEAN = get_bench_mean(BENCH_JSON2SBP, "rust")

validate_thresholds(THRESHOLDS_JSON2SBP, MEANS_JSON2SBP, JSON2SBP_RUST_MEAN)

BENCHMARK_INPUT_JSON2JSON_GZ = open("test_data/benchmark.json2json.gz", "rb")
JSON_DATA = gzip.decompress(BENCHMARK_INPUT_JSON2JSON_GZ.read())

with open("test_data/benchmark.json2json", "wb") as BENCHMARK_INPUT_JSON2JSON:
    BENCHMARK_INPUT_JSON2JSON.write(JSON_DATA)

subprocess.run(
    ['hyperfine',  # '--show-output',
     '--export-json', 'benchmark_json2json.json',
     '-L', 'lang', 'rust,haskell',
     './test_data/benchmark/json2json_{lang}.py'],
    check=True)

BENCH_JSON2JSON = json.load(open('benchmark_json2json.json'))

MEANS_JSON2JSON = {
    "haskell": get_bench_mean(BENCH_JSON2JSON, "haskell"),
}

JSON2JSON_RUST_MEAN = get_bench_mean(BENCH_JSON2JSON, "rust")

validate_thresholds(THRESHOLDS_JSON2JSON, MEANS_JSON2JSON, JSON2JSON_RUST_MEAN)
