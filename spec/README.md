## SBP Definitions

A quite basic, template-based generator for SBP bindings in different
languages.

## Usage

```shell
# Output C bindings.
python sbp/generator.py -i ../spec/yaml/swift/sbp/ --output_dir ../c/ --c --verbose

# Output Python bindings.
python sbp/generator.py -i ../spec/yaml/swift/sbp/ --output_dir ../python/ --c --verbose

```

## LICENSE

Copyright © 2015 Swift Navigation
