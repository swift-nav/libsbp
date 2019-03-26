#!/bin/sh

############################################################################
#
# Use this script to automatically update the Swift common cmake modules
# included in another project
#
# This script must not be called from within the swift common cmake modules
# repository, it is only for use in updating other projects.
#
# By default it will pull the latest version from the master branch, pass
# a branch name as a parameter to select something else
#
# This script will stage all changes and set up a commit. Delete the commit
# message to abort.
#
# Be careful when updating common cmake modules, any changes made in a local
# repository will be overwritten with the canonical version. Always change
# common modules in the common module repository.
#
############################################################################

if [ "x$1" == "xSKIP_CHECKS" ];
then
  shift;
else
  if ! git remote >/dev/null 2>&1;
  then
    echo "This doesn't look like a git repository. You probably don't want"
    echo "to run this script in this location"
    exit 1
  fi
  
  if git rev-list a34c3c8814b0d75ddb56162b6d282362ed6b9a9e >/dev/null 2>&1 ;
  then
    echo "This script must not be run from the Swift common cmake modules repository"
    echo "Change to the local cmake directory in the project you wish to update"
    echo "and run it again from there"
    exit 1
  fi
  
  if ! git diff-index --cached --quiet HEAD ;
  then
    echo "You have staged changes. Commit or unstage them before"
    echo "running this command"
    exit 1
  fi
  
  if ! git diff-index --quiet HEAD ;
  then
    echo "You have uncommitted changes. Commit or stash them"
    echo "before running this command"
    exit 1
  fi
fi

BRANCH=master
if [ $# -eq 1 ];
then
  BRANCH=$1
  shift
fi

TMPDIR=$(mktemp -d -p .)

cat > ${TMPDIR}/update.sh << EOF
echo "Updating common cmake modues to latest version"
if ! git clone -q -b ${BRANCH} --depth 1 git@github.com:swift-nav/cmake.git ${TMPDIR}/cmake ;
then
  rm -rf ${TMPDIR}
  echo "Failed to fetch ${BRANCH} from repo"
  exit 1
fi

cp -r ${TMPDIR}/cmake/* .
for f in ${TMPDIR}/cmake/*;
do
  git add "\$(basename \$f)"
done
if git diff-index --cached --quiet HEAD;
then
  echo "No changes"
else
  git commit --quiet --edit -m "Updating cmake modules to latest version from ${BRANCH}"
  echo "Done"
fi
  
rm -rf ${TMPDIR}
EOF

chmod +x ${TMPDIR}/update.sh
exec ${TMPDIR}/update.sh
