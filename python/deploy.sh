#!/bin/sh

set -e

deploy_dir=$(mktemp -d)
#trap 'rm -rf "$deploy_dir"' EXIT

echo "$deploy_dir"
cd "$deploy_dir"

echo ">>> Building staging area for deployment ..."

mkdir module

cp -r "$(dirname "$0")"/../.git .

cp -r "$(dirname "$0")"/.coveragerc module/.
cp -r "$(dirname "$0")"/.gitignore module/.

cp -r "$(dirname "$0")"/* module/.

echo ">>> Pruning ..."
rm -r -f module/docs/_build
rm -r -f module/build/*

echo ">>> Patching setup.py ..."
sed -i.backup 's@IS_RELEASED = False@IS_RELEASED = True@' module/setup.py

cd module

echo ">>> Building Python wheel ..."
python setup.py sdist bdist_wheel

echo ">>> Uploading Python wheel ..."
twine upload -u "$PYPI_USERNAME" -p "$PYPI_PASSWORD" "dist/sbp-$SBP_VERSION-*.whl"
