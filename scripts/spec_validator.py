"""
Script for ensuring that messages are not changed in a backwards incompatible way
"""

import argparse
import glob
import logging
import os
import re
import sys

from typing import List, Optional, Tuple

import yaml


PACKAGES = {}
DEP_MESSAGE_PATTERN = re.compile("^.*(_DEP)|(_DEP_[A-Z])$")


def unpack(value: dict):
    return next(iter(value.items()))


def flatten(definitions: List[dict]) -> dict:
    # The yaml gets parsed into a list of dictionary objects with 1 entry each.
    # The entry is a mapping of the definition name to another dictionary object.
    # This flattens the list of dictionaries into a dictionary of dictionaries.
    # This is a much more convenient data structure to perform comparisons.
    d = {}
    for item in definitions:
        key, value = unpack(item)
        d[key] = value
    return d


def is_message(name: str) -> bool:
    return "MSG" in name


def parse_packages(root: str) -> dict:
    paths = glob.glob(f"{root}/*.yaml")
    d = {}
    for path in paths:
        with open(path, "r") as file:
            spec = yaml.safe_load(file)
            package = unpack(spec)[1]
            PACKAGES[package] = os.path.basename(path)
            definitions = spec["definitions"]
            d[package] = flatten(definitions)
    return d


def type_to_digit(type_str: str) -> int:
    return int("".join(filter(str.isdigit, type_str)))


def get_upper(bitfield: str) -> int:
    return int(bitfield.split("-")[1])


def check_bitfield_range(type_str: str, bitfields: List[dict]) -> None:
    limit = type_to_digit(type_str)
    for item in bitfields:
        bitfield = unpack(item)[0]
        val = bitfield if isinstance(bitfield, int) else get_upper(bitfield)
        if not val < limit:
            raise RuntimeError(
                f"Invalid Bitfield Range!: Type {type}, Range: {bitfield}"
            )


def check_incoming_packages(packages: dict) -> None:
    logging.info("Checking Bitfield Ranges")
    for key, value in packages.items():
        logging.info(f"Processing Package: {key}")
        for name, definition in value.items():
            logging.info(f"Processing Definition: {name}")
            if "fields" in definition:
                fields = definition["fields"]
                for item in fields:
                    name, field = unpack(item)
                    if "fields" in field:
                        logging.info(f"Processing Field: {name}")
                        type = field["type"]
                        bitfields = field["fields"]
                        check_bitfield_range(type, bitfields)
            else:  # skip empty messages
                continue


def check_package_exists(previous_package_name: str, current_packages: dict) -> None:
    if previous_package_name not in current_packages:
        raise RuntimeError(
            f"Package: {previous_package_name} has been renamed or removed"
        )


def validate_bitfields(
    previous_bitfield: List[dict], current_bitfield: List[dict]
) -> None:
    previous = flatten(previous_bitfield)
    current = flatten(current_bitfield)
    for key, value in previous.items():
        if "desc" in value:  # not all messages have a desc
            if value["desc"] == "Reserved":
                continue
        if key not in current:
            raise RuntimeError(
                "Breaking Message Mutation Detected!\n"
                f"Bitfield {key}, has been modified"
            )


def validate_fields(filename: str, previous_fields: dict, current_fields: dict) -> None:
    for previous, current in zip(previous_fields, current_fields):
        previous_key, previous_value = unpack(previous)
        current_key, current_value = unpack(current)
        if previous_key != current_key:
            logging.warning(
                f" {filename} Name of Field Changed: {previous_key} to {current_key}"
            )
        if "fields" in previous_value:
            logging.info(f"Processing Bitfield: {previous_key}")
            previous_bitfield = previous_value["fields"]
            current_bitfield = current_value["fields"]
            validate_bitfields(previous_bitfield, current_bitfield)
        previous_type = previous_value["type"]
        current_type = current_value["type"]
        if current_type != previous_type:
            raise RuntimeError(
                "Breaking Message Mutation Detected!\n"
                f"Field (previous, current): {previous_key}, {current_key}\n"
                f"Type (previous, current): {previous_type}, {current_type}"
            )


def lookup_by_id(package: dict, msg_id: int) -> Optional[Tuple[str, dict]]:
    for (key, msg) in package.items():
        if msg["id"] == msg_id:
            return (key, msg)
    return None


def validate_id(
    key: str,
    previous: dict,
    current: dict,
    previous_definitions: dict,
    current_definitions: dict,
) -> None:
    if is_message(key):
        prev_id = previous["id"]
        curr_id = current["id"]
        if prev_id != curr_id:
            keymsg = lookup_by_id(current_definitions, prev_id)
            if not keymsg:
                raise RuntimeError(
                    "Expected to Find Message ID In Current Package!\n"
                    f"Previous ID: {prev_id}, Current ID: {curr_id}"
                )
            key, _msg = keymsg
            if not DEP_MESSAGE_PATTERN.match(key):
                raise RuntimeError(
                    "Message ID Change Detected!\n"
                    f"Previous ID: {prev_id}, Current ID: {curr_id}"
                )


def validate_definitions(
    filename: str, previous_definitions: dict, current_definitions: dict
) -> None:
    for key in previous_definitions.keys():
        logging.info(f"Processing Definition: {key}")
        previous = previous_definitions[key]
        current = current_definitions[key]
        validate_id(key, previous, current, previous_definitions, current_definitions)
        # bail if message has no fields
        # assumes adding fields to an empty message is ok.
        if "fields" not in previous:
            continue
        previous_fields = previous["fields"]
        current_fields = current["fields"]
        validate_fields(filename, previous_fields, current_fields)


def validate(previous: str, current: str) -> None:
    previous_packages = parse_packages(previous)
    current_packages = parse_packages(current)
    check_incoming_packages(current_packages)
    for previous_package in previous_packages.keys():
        logging.info(f"Processing Package: {previous_package}")
        check_package_exists(previous_package, current_packages)
        filename = PACKAGES[previous_package]
        previous_def = previous_packages[previous_package]
        current_def = current_packages[previous_package]
        validate_definitions(filename, previous_def, current_def)


def init() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("previous", help="path to previous yaml specs")
    parser.add_argument("current", help="path to current yaml specs")
    return parser.parse_args()


def main() -> None:
    args = init()
    logging.basicConfig(level=logging.INFO)
    validate(args.previous, args.current)


if __name__ == "__main__":
    main()
