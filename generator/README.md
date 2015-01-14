## SBP Generator

A quite basic, template-based generator for generating SBP bindings in
different languages.

## Usage

Courtesy of `argparse`:

```
usage: generator.py [-h] -i INPUT_FILE -o OUTPUT_DIR [--python] [--c] [-v]

Swift Navigation SBP generator.

optional arguments:
  -h, --help            show this help message and exit
  -i INPUT_FILE, --input_file INPUT_FILE
                        Input spec file or directory.
  -o OUTPUT_DIR, --output_dir OUTPUT_DIR
                        Output directory.
  --python              Target language: Python.
  --c                   Target language: C.
  -v, --verbose         Print debugging info.
```

For example,

```shell
# Output C bindings:
python sbp/generator.py -i ../spec/yaml/swift/sbp/ -o ../c/ --c

# Output Python bindings:
python sbp/generator.py -i ../spec/yaml/swift/sbp/ -o ../python/ --c
python sbp/generator.py -i ../spec/yaml/swift/sbp/navigation.yaml -o ../python/ --c

```

## Testing and Deployment

```shell
# Install dependencies
pip install -r requirements.txt

# Running tests
py.test -q -vv test/

# Deploying to pypi


```

## LICENSE

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.
