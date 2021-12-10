#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Author: Douglas Creager <dcreager@dcreager.net>
# This file is placed into the public domain.
# Adapted from Gist: https://gist.github.com/3067886

# Calculates the current version number.  If possible, this is the
# output of “git describe”, modified to conform to the versioning
# scheme that setuptools uses.  If “git describe” returns an error
# (most likely because we're in an unpacked copy of a release tarball,
# rather than in a git working copy), then we fall back on reading the
# contents of the RELEASE-VERSION file.
#
# To use this script, simply import it your setup.py file, and use the
# results of get_git_version() as your package version:
#
# from version import *
#
# setup(
#     version=get_git_version(),
#     .
#     .
#     .
# )
#
# This will automatically update the RELEASE-VERSION file, if
# necessary.  Note that the RELEASE-VERSION file should *not* be
# checked into git; please add it to your top-level .gitignore file.
#
# You'll probably want to distribute the RELEASE-VERSION file in your
# sdist tarballs; to do this, just create a MANIFEST.in file that
# contains the following line:
#
#   include RELEASE-VERSION

__all__ = ("get_git_version", )

from subprocess import Popen, PIPE


def call_git_describe():
    try:
        p = Popen(['git', 'describe', '--tags', '--dirty', '--always'],
                  stdout=PIPE, stderr=PIPE)
        p.stderr.close()
        line = p.stdout.readlines()[0].decode('ascii')
        return line.strip()
    except Exception:
        return None


def read_release_version():
    try:
        from sbp import __version__ as version
        return version
    except Exception:
        return None


def get_git_version():
    # Read in the version that's currently in RELEASE-VERSION.
    release_version = read_release_version()

    # First try to get the current version using “git describe”.
    version = call_git_describe()

    # Take off the leading if present.
    if version is not None and version[0] == 'v':
        version = version[1:]

    # Adapt to PEP 386 compatible versioning scheme
    version = pep386adapt(version)

    # If that doesn't work, fall back on the value that's in
    # RELEASE-VERSION.
    if version is None:
        version = release_version

    # If we still don't have anything, that's an error.
    if version is None:
        raise ValueError("Cannot find the version number!")

    # Finally, return the current version.
    return version


def pep386adapt(version):
    if version is not None and '-' in version:
        # adapt git-describe version to be in line with PEP 386
        # Break PEP 386 a bit here and append the Git hash
        parts = version.split('-')
        if len(parts) > 2:
            version = '%s.dev%s+%s' % (parts[0], parts[1], '-'.join(parts[2:]))
        return version
    else:
        return version


VERSION = get_git_version()


if __name__ == "__main__":
    print(VERSION)
