#!/usr/bin/env python

#
# Python setuptools specification for Swift Navigation's libsbp
#
# Version handling code pulled from Enthought's TraitsUI:
#   https://github.com/swift-nav/traitsui/blob/swift-2019.01/setup.py
#

import warnings
from setuptools import setup, find_packages

import re
import os

import subprocess

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
  'Programming Language :: Python :: 3.5',
  'Programming Language :: Python :: 3.6',
  'Programming Language :: Python :: 3.7',
  'Programming Language :: Python :: 3.8',
  'Programming Language :: Python :: 3.9',
]

PACKAGES = find_packages(exclude=["tests", "bench", "tests.*"])

PLATFORMS = [
  'linux',
  'osx',
  'win32',
]

setup_py_dir = os.path.dirname(os.path.abspath(__file__))

def _read_release_version():
    relver_path = os.path.join(setup_py_dir, 'sbp/RELEASE-VERSION')
    try:
        with open(relver_path, "r") as f:
            version = f.readlines()[0]
            return version.strip()
    except IOError as ex:
        warnings.warn("Error reading version: {}".format(ex))
        return "0.0.0"


def read_release_version():
    major, minor, patch = _read_release_version().split('.')
    return (int(major), int(minor), patch)


MAJOR, MINOR, PATCH = read_release_version()
IS_RELEASED = os.environ.get('IS_RELEASED', '') != ''

VERSION = '%d.%d.%s' % (MAJOR, MINOR, PATCH)

VERSION_PY_TEMPLATE = """\
# THIS FILE IS GENERATED FROM TRAITS SETUP.PY
version = '{version}'
full_version = '{full_version}'
git_revision = '{git_revision}'
is_released = {is_released}
if not is_released:
    version = full_version
"""

VERSION_PY_PATH = 'sbp/_version.py'


# Return the git revision as a string
def git_version():
    def _minimal_ext_cmd(cmd):
        # construct minimal environment
        env = {}
        for k in ['SYSTEMROOT', 'PATH']:
            v = os.environ.get(k)
            if v is not None:
                env[k] = v
        # LANGUAGE is used on win32
        env['LANGUAGE'] = 'C'
        env['LANG'] = 'C'
        env['LC_ALL'] = 'C'
        out = subprocess.Popen(
            cmd, stdout=subprocess.PIPE, env=env,
        ).communicate()[0]
        return out
    try:
        out = _minimal_ext_cmd(['git', 'describe', '--tags'])
    except OSError:
        out = b''
    git_description = out.strip().decode('ascii')
    expr = r'.*?\-(?P<count>\d+)-g(?P<hash>[a-fA-F0-9]+)'
    match = re.match(expr, git_description)
    if match is None:
        git_revision, git_count = 'Unknown', '0'
    else:
        git_revision, git_count = match.group('hash'), match.group('count')
    return git_revision, git_count


def write_version_py(filename=VERSION_PY_PATH):

    fullversion = VERSION
    if os.path.exists(os.path.join(setup_py_dir, '..', '.git')):
        git_rev, dev_num = git_version()
    elif os.path.exists(VERSION_PY_PATH):
        # must be a source distribution, use existing version file
        try:
            from sbp._version import git_revision as git_rev
            from sbp._version import full_version as full_v
        except ImportError:
            raise ImportError("Unable to import git_revision. Try removing "
                              "sbp/_version.py and the build directory "
                              "before building.")

        match = re.match(r'.*?\.dev(?P<dev_num>\d+)', full_v)
        if match is None:
            dev_num = '0'
        else:
            dev_num = match.group('dev_num')
    else:
        git_rev = 'Unknown'
        dev_num = '0'

    if not IS_RELEASED:
        # According to the original source for this setup.py
        # version handling (see link at top of the file):
        #
        # We may need to add the git rev number outside of
        # write_version_py(), otherwise the import of ._version
        # might mess up the build under Python 3.
        #
        fullversion += '.dev{0}+g{1}'.format(dev_num, git_rev)

    filename_fullpath = os.path.join(setup_py_dir, filename)
    print(filename_fullpath)

    with open(filename_fullpath, "wt") as fp:
        fp.write(VERSION_PY_TEMPLATE.format(version=VERSION,
                                            full_version=fullversion,
                                            git_revision=git_rev,
                                            is_released=IS_RELEASED))


if __name__ == "__main__":

    with open(os.path.join(setup_py_dir, 'README.rst'), 'rb') as f:
        readme = f.read().decode('utf8')

    write_version_py()

    from sbp import __version__ as sbp_version
    print("Building/installing libsbp version {0} (read version: {1})".format(sbp_version, VERSION))

    ext_modules = None

    with open(os.path.join(setup_py_dir, 'requirements.txt')) as f:
        INSTALL_REQUIRES = [i.strip() for i in f.readlines()]

    with open(os.path.join(setup_py_dir, 'test_requirements.txt')) as f:
        TEST_REQUIRES = [i.strip() for i in f.readlines()]

    print("Discovered packages: {0}".format(PACKAGES))

    setup(
        name='sbp',
        version=sbp_version,
        description='Python bindings for Swift Binary Protocol',
        long_description=readme,
        author='Swift Navigation',
        author_email='dev@swift-nav.com',
        url='https://github.com/swift-nav/libsbp',
        classifiers=CLASSIFIERS,
        packages=PACKAGES,
        platforms=PLATFORMS,
        install_requires=INSTALL_REQUIRES,
        tests_require=TEST_REQUIRES,
        use_2to3=False,
        zip_safe=False,
        ext_modules=ext_modules,
        scripts=['bin/sbp2json'],
        extras_require={
          'sbp2json': [
              'python-rapidjson~=1.0',
              'pybase64~=1.1',
          ]
        })
