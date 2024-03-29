#!/bin/sh

set -e

DOCKER_IMAGE=swiftnav/libsbp-build:2023-12-19
RUN_DOCKER="docker run -it --rm -v $PWD:/mnt/workspace -t ${DOCKER_IMAGE}"
VERSION=$(./scripts/get_release_version.py $(git describe --match 'v*' --always --tags))

if [ $# -ne 0 ]; then
	VERSION=$1
	shift
fi

if [ -z "${CHANGELOG_GITHUB_TOKEN}" ]; then
	echo "You must set CHANGELOG_GITHUB_TOKEN in your environment before running this command"
	exit 1
fi

git diff --exit-code >/dev/null 2>&1
if [ $? -ne 0 ]; then
	echo "Working directory is not clean. Remove any and all changes before running this command"
	exit 1
fi

echo "Releasing libsbp version ${VERSION}"

echo "Creating initial commit and tag"
git commit --allow-empty -m "Release ${VERSION}"
git tag -a ${VERSION} -m "Version ${VERSION} of libsbp."

echo "Building python"
${RUN_DOCKER} make gen-python

echo "Updating tag"
git add .
git commit --amend -a -m "Release ${VERSION}"
git tag -f -a ${VERSION} -m "Version ${VERSION} of libsbp."

echo "Building language bindings"
${RUN_DOCKER} make gen-java gen-javascript gen-protobuf
${RUN_DOCKER} make gen-c gen-haskell gen-javascript gen-rust

echo "Updating tag"
git add .
git commit --amend -a -m "Release ${VERSION}"
git tag -f -a ${VERSION} -m "Version ${VERSION} of libsbp."

echo "Rebuilding javascript"
${RUN_DOCKER} make gen-javascript
${RUN_DOCKER} make gen-javascript

echo "Updating tag"
git add .
git commit --amend -a -m "Release ${VERSION}"
git tag -f -a ${VERSION} -m "Version ${VERSION} of libsbp."

echo "Buliding kaitai"
${RUN_DOCKER} make gen-kaitai

echo "Updating tag"
git add .
git commit --amend -a -m "Release ${VERSION}"
git tag -f -a ${VERSION} -m "Version ${VERSION} of libsbp."

echo "Building documentation"
${RUN_DOCKER} make docs

echo "Updating tag"
git add .
git commit --amend -a -m "Release ${VERSION}"
git tag -f -a ${VERSION} -m "Version ${VERSION} of libsbp."

echo "Generating changelog"
make release
./scripts/merge_changelogs.py ${VERSION}
rm -f DRAFT_CHANGELOG.md

echo "Updating tag"
git add .
git commit --amend -a -m "Release ${VERSION}"
git tag -f -a ${VERSION} -m "Version ${VERSION} of libsbp."

git diff HEAD~1

cat <<EOF
A new commit and tag has been created. Look at the above diff and verify the contents. If everything looks good you can push to master straight away.

If there are any mistakes now is the time to correct them. Make any changes which are required then update the tag by running:

git add <files>
git commit --amend -a -m "Release ${VERSION}"
git tag -f -a ${VERSION} -m "Version ${VERSION} of libsbp."

Once you have fixed everything you can push to master

Once pushed prepare for the next release by running ./scripts/prep_for_next_release.sh
EOF
