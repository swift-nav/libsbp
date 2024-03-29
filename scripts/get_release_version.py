#!/usr/bin/env python
import sys

major, minor, patch = sys.argv[1].split(".")[:3]
if "-" in patch:
    patch = patch.split("-")[0]
print(f"{major}.{minor}.{int(patch) + 1}")
