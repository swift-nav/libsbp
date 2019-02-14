#!/bin/sh

set -e

deploy_dir=$(mktemp -d)
trap 'rm -rf "$deploy_dir"' EXIT

cd "$deploy_dir"

echo ">>> Building staging area for deployment ..."

cp -r "$(dirname "$0")"/.coveragerc .
cp -r "$(dirname "$0")"/.gitignore .

cp -r "$(dirname "$0")"/* .

echo ">>> Pruning ..."
rm -r -f docs/_build
rm -r -f build/*

echo ">>> Patching setup.py ..."
sed -i.backup 's@IS_RELEASED = False@IS_RELEASED = True@' setup.py

echo ">>> Building Python wheel ..."
python setup.py sdist bdist_wheel

echo ">>> Uploading Python wheel ..."
twine upload -u "$PYPI_USERNAME" -p "$PYPI_PASSWORD" "dist/sbp-$SBP_VERSION-*.whl"
