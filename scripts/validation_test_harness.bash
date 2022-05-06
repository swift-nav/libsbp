#!/usr/bin/env bash

if ! python scripts/spec_validator.py spec/validation/previous/field_type_changed spec/validation/current/field_type_changed; then
        echo "Check Field Type Changed: PASS"
else
        echo "Check Field Type Changed: FAIL"
        exit 1
fi

if ! python scripts/spec_validator.py spec/validation/previous/message_id_changed spec/validation/current/message_id_changed; then
        echo "Check Message ID Changed: PASS"
else
        echo "Check Message ID Changed: FAIL"
        exit 1
fi

if ! python scripts/spec_validator.py spec/validation/previous/message_id_changed_dep_fail spec/validation/current/message_id_changed_dep_fail; then
        echo "Check Message ID (Dep) Changed: PASS"
else
        echo "Check Message ID (Dep) Changed: FAIL"
        exit 1
fi

if python scripts/spec_validator.py spec/validation/previous/message_id_changed_dep spec/validation/current/message_id_changed_dep; then
        echo "Check Message ID (Dep) Changed: PASS"
else
        echo "Check Message ID (Dep) Changed: FAIL"
        exit 1
fi

if ! python scripts/spec_validator.py spec/validation/previous/field_order_changed spec/validation/current/field_order_changed; then
        echo "Check Field Order Changed: PASS"
else
        echo "Check Field Order Changed: FAIL"
        exit 1
fi

if python scripts/spec_validator.py spec/validation/previous/field_name_changed spec/validation/current/field_name_changed; then
        echo "Check Field Name Changed: PASS"
else
        echo "Check Field Name Changed: FAIL"
        exit 1
fi

if ! python scripts/spec_validator.py spec/validation/previous/new_field_appended spec/validation/current/new_field_appended; then
        echo "Check New Field Appended: PASS"
else
        echo "Check New Field Appended: FAIL"
        exit 1
fi

if python scripts/spec_validator.py spec/validation/previous/new_message_added spec/validation/current/new_message_added; then
        echo "Check New Message Added: PASS"
else
        echo "Check New Message Added: FAIL"
        exit 1
fi

if python scripts/spec_validator.py spec/validation/previous/new_package_added spec/validation/current/new_package_added; then
        echo "Check New Package Added: PASS"
else
        echo "Check New Package Added: FAIL"
        exit 1
fi

if ! python scripts/spec_validator.py spec/validation/previous/change_bitfield_value spec/validation/current/change_bitfield_value; then
        echo "Check Bitfield Changed: PASS"
else
        echo "Check Bitfield Changed: FAIL"
        exit 1
fi

if python scripts/spec_validator.py spec/validation/previous/unreserve_bitfield spec/validation/current/unreserve_bitfield; then
        echo "Check Modify Reserved Flags: PASS"
else
        echo "Check Modify Reserved Flags: FAIL"
        exit 1
fi

if ! python scripts/spec_validator.py spec/validation/previous/remove_package spec/validation/current/remove_package; then
        echo "Check Remove Package: PASS"
else
        echo "Check Remove Package: FAIL"
        exit 1
fi

if ! python scripts/spec_validator.py spec/validation/previous/invalid_bitfield_range spec/validation/current/invalid_bitfield_range; then
        echo "Check Invalid Bitfield Range: PASS"
else
        echo "Check Invalid Bitfield Range: FAIL"
        exit 1
fi