#!/usr/bin/env bash

set -euo pipefail
IFS=$'\n\t'

[[ -n "$PYPI_USERNAME" ]] || \
  { printf "\n!!! Please set PYPI_USERNAME in the environment !!!\n\n"; exit 1; }

[[ -n "$PYPI_PASSWORD" ]] || \
  { printf "\n!!! Please set PYPI_PASSWORD in the environment !!!\n\n"; exit 1; }

if ! command -v conda; then
  { printf "\n!!! Please install conda to deploy python !!!\n\n"; exit 1; }
fi

for py_version in 2.7 3.5 3.7

do
  echo ">>> Building wheel for Python $py_version ..."
  conda_dir=$(mktemp -d)
  conda create --yes -p "$conda_dir" python=$py_version

  # Activate conda
  {
    # Workaround bug in activate code...
    export PS1=''

    eval "$(conda shell.bash hook)"
    # shellcheck disable=SC1091
    conda activate "$conda_dir"
  }

  conda install --yes \
    cython virtualenv twine wheel

  pip install --user -r setup_requirements.txt

  deploy_dir=$(mktemp -d)
  trap 'rm -rf "$deploy_dir" "$conda_dir"' EXIT

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
  python setup.py bdist_wheel

  echo ">>> Uploading Python wheel ..."
  twine upload -u "$PYPI_USERNAME" -p "$PYPI_PASSWORD" "dist/sbp-$SBP_VERSION-*.whl"

  conda deactivate
done
