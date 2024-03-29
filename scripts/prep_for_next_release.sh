#!/bin/sh

set -e

DOCKER_IMAGE=swiftnav/libsbp-build:2023-12-19
RUN_DOCKER="docker run -it --rm -v $PWD:/mnt/workspace -t ${DOCKER_IMAGE}"
VERSION=$(./scripts/get_release_version.py $(git describe --match 'v*' --always --tags))

git diff --exit-code >/dev/null 2>&1
if [ $? -ne 0 ]; then
	echo "Working directory is not clean. Remove any and all changes before running this command"
	exit 1
fi

echo "Creating initial commit"
git commit --allow-empty -m "prep for next release #no_auto_pr"

echo "Building python"
${RUN_DOCKER} make gen-python

echo "Updating commit"
git add .
git commit --amend -a -m "prep for next release #no_auto_pr"

echo "Building language bindings"
${RUN_DOCKER} make gen-java gen-javascript gen-protobuf
${RUN_DOCKER} make gen-c gen-haskell gen-javascript gen-rust

echo "Updating commit"
git add .
git commit --amend -a -m "prep for next release #no_auto_pr"

echo "Rebuilding javascript"
${RUN_DOCKER} make gen-javascript
${RUN_DOCKER} make gen-javascript

echo "Updating commit"
git add .
git commit --amend -a -m "prep for next release #no_auto_pr"

echo "Buliding kaitai"
${RUN_DOCKER} make gen-kaitai

echo "Updating commit"
git add .
git commit --amend -a -m "prep for next release #no_auto_pr"

git diff HEAD~1

cat <<EOF
A new commit and tag has been created. Look at the above diff and verify the contents. If everything looks good you can push to master straight away.

If there are any mistakes now is the time to correct them. Make any changes which are required then update the tag by running:

git add <files>
git commit --amend -a -m "prep for next release #no_auto_pr"

Once you have fixed everything you can push to master
EOF
