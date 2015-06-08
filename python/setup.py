#!/usr/bin/env python

from setuptools import setup
from subprocess import Popen, PIPE
import os

def call_git_describe():
    try:
        p = Popen(['git', 'describe', '--tags', '--dirty', '--always'],
                  stdout=PIPE, stderr=PIPE)
        p.stderr.close()
        line = p.stdout.readlines()[0]
        return line.strip()
    except:
        return None

def read_release_version():
    try:
        f = open(os.path.join(os.path.dirname(__file__), 'RELEASE-VERSION'), "r")
        try:
            version = f.readlines()[0]
            return version.strip()
        finally:
            f.close()
    except:
        return None

def write_release_version(version):
    f = open(os.path.join(os.path.dirname(__file__), 'RELEASE-VERSION'), "w")
    f.write("%s\n" % version)
    f.close()

def pep386adapt(version):
    if version is not None and '-' in version:
        # adapt git-describe version to be in line with PEP 386
        # Break PEP 386 a bit here and append the Git hash
        parts = version.split('-')
        if len(parts) > 2:
          version = '%s.post%s-%s' % (
              parts[0], parts[1],
              '-'.join(parts[2:])
          )
        return version
    else:
        return version

def get_git_version():
    # Read in the version that's currently in RELEASE-VERSION.
    release_version = read_release_version()

    # First try to get the current version using 'git describe'.
    version = call_git_describe()

    # Take off the leading if present.
    if version[0] == 'v':
      version = version[1:]

    #adapt to PEP 386 compatible versioning scheme
    version = pep386adapt(version)

    # If that doesn't work, fall back on the value that's in
    # RELEASE-VERSION.
    if version is None:
        version = release_version

    # If we still don't have anything, that's an error.
    if version is None:
        raise ValueError("Cannot find the version number!")

    # If the current version is different from what's in the
    # RELEASE-VERSION file, update the file to be current.
    if version != release_version:
        write_release_version(version)

    # Finally, return the current version.
    return version

VERSION = get_git_version()

CLASSIFIERS = [
  'Intended Audience :: Developers',
  'Intended Audience :: Science/Research',
  'Operating System :: POSIX :: Linux',
  'Operating System :: MacOS :: MacOS X',
  'Operating System :: Microsoft :: Windows',
  'Programming Language :: Python',
  'Topic :: Scientific/Engineering :: Interface Engine/Protocol Translator',
  'Topic :: Software Development :: Libraries :: Python Modules',
  'Programming Language :: Python :: 2.7',
]

PACKAGES = [
  'sbp',
  'sbp.client',
  'sbp.client.drivers',
  'sbp.client.loggers',
]

PLATFORMS = [
  'linux',
  'osx',
  'win32',
]

cwd = os.path.abspath(os.path.dirname(__file__))
with open(cwd + '/README.rst') as f:
  readme = f.read()

with open(cwd + '/requirements.txt') as f:
  INSTALL_REQUIRES = [i.strip() for i in f.readlines()]

setup(name='sbp',
      description='Python bindings for Swift Binary Protocol',
      long_description=readme,
      version=VERSION,
      author='Swift Navigation',
      author_email='dev@swiftnav.com',
      url='https://github.com/swift-nav/libsbp',
      classifiers=CLASSIFIERS,
      packages=PACKAGES,
      platforms=PLATFORMS,
      install_requires=INSTALL_REQUIRES,
      use_2to3=False,
      zip_safe=False)
