import argparse
import glob
import logging
import os
import sys
import yaml


packages = {}


def unpack(dict):
    return next(iter(dict.items()))


def flatten(definitions):
    # The yaml gets parsed into a list of dictionary objects with 1 entry each.
    # The entry is a mapping of the definition name to another dictionary object.
    # This flattens the list of dictionaries into a dictionary of dictionaries.
    # This is a much more convenient data structure to perform comparisons.
    d = {}
    for item in definitions:
        key, value = unpack(item)
        d[key] = value
    return d


def is_message(name):
    return "MSG" in name


def parse_packages(root):
    paths = glob.glob(f"{root}/*.yaml")
    d = {}
    for path in paths:
        with open(path, "r") as file:
            spec = yaml.safe_load(file)
            package = unpack(spec)[1]
            packages[package] = os.path.basename(path)
            definitions = spec["definitions"]
            d[package] = flatten(definitions)
    return d


def type_to_digit(type):
    return int("".join(filter(str.isdigit, type)))


def get_upper(bitfield):
    return int(bitfield.split("-")[1])


def check_bitfield_range(type, bitfields):
    limit = type_to_digit(type)
    for item in bitfields:
        bitfield = unpack(item)[0]
        val = bitfield if isinstance(bitfield, int) else get_upper(bitfield)
        if not val < limit:
            raise RuntimeError(
                f"Invalid Bitfield Range!: Type {type}, Range: {bitfield}"
            )


def check_incoming_packages(packages):
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


def check_package_exists(previous, current):
    if previous not in current:
        raise RuntimeError(
            f"Package: {previous} has been renamed or removed"
        )


def validate_bitfields(previous_bitfield, current_bitfield):
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


def validate_fields(filename, previous_fields, current_fields):
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


def validate_id(key, previous, current):
    if is_message(key):
        prev_id = previous["id"]
        curr_id = current["id"]
        if prev_id != curr_id:
            raise RuntimeError(
                "Message ID Change Detected!\n"
                f"Previous ID: {prev_id}, Current ID: {curr_id}"
            )


def validate_definitions(filename, previous_definitions, current_definitions):
    for key in previous_definitions.keys():
        logging.info(f"Processing Definition: {key}")
        previous = previous_definitions[key]
        current = current_definitions[key]
        validate_id(key, previous, current)
        # bail if message has no fields
        # assumes adding fields to an empty message is ok.
        if "fields" not in previous:
            continue
        previous_fields = previous["fields"]
        current_fields = current["fields"]
        validate_fields(filename, previous_fields, current_fields)


def validate(previous, current):
    previous_packages = parse_packages(previous)
    current_packages = parse_packages(current)
    check_incoming_packages(current_packages)
    for previous_package in previous_packages.keys():
        logging.info(f"Processing Package: {previous_package}")
        check_package_exists(previous_package, current_packages)
        filename = packages[previous_package]
        previous_def = previous_packages[previous_package]
        current_def = current_packages[previous_package]
        validate_definitions(filename, previous_def, current_def)


def init():
    parser = argparse.ArgumentParser()
    parser.add_argument("previous", help="path to previous yaml specs")
    parser.add_argument("current", help="path to current yaml specs")
    return parser.parse_args()


def main():
    args = init()
    logging.basicConfig(level=logging.INFO)
    validate(args.previous, args.current)


if __name__ == "__main__":
    main()
