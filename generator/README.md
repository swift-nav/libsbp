## SBP Generator

A quite basic, template-based generator for generating SBP bindings in
different languages.

## Usage

Courtesy of `argparse`:

```
usage: generator.py [-h] -i INPUT_FILE -o OUTPUT_DIR [--python] [--c] [--docs] [-v]

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
python sbpg/generator.py -i ../spec/yaml/swiftnav/sbp/ -o ../c/ --c

# Output Python bindings:
python sbpg/generator.py -i ../spec/yaml/swiftnav/sbp/ -o ../python/ --python
python sbpg/generator.py -i ../spec/yaml/swiftnav/sbp/navigation.yaml -o ../python/ --python

# Output LaTeX documentation
python sbpg/generator.py -i ../spec/yaml/swiftnav/sbp/ -o ../latex/ --latex

```

## Testing and Deployment

```shell
# (Optional) Install LaTeX dependencies - ~2 GB!
sudo apt-get install texlive-extra texlive-fonts-extra
sudo pip install sphinx

# Install dependencies
pip install -r requirements.txt

# Running tests
py.test -q -vv tests/

# Deploying to pypi


```

## LICENSE

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.
