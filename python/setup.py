#!/usr/bin/env python

from setuptools import setup
import os

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
  'sbp.client.util',
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

with open(cwd + '/test_requirements.txt') as f:
    TEST_REQUIRES = [i.strip() for i in f.readlines()]


def sbp_root():
    return os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))


def do_parse(root, config):
    import subprocess
    from setuptools_scm.version import meta
    tag = None
    cwd = os.getcwd()
    try:
        os.chdir(root)
        describe_output = subprocess.check_output(['git', 'describe'])
        tag = describe_output.decode('ascii').strip()
    except OSError:
        return meta("99.99.99")
    finally:
        os.chdir(cwd)
    parts = tag.split('-')
    kw_params = {}
    version = parts[0].lstrip('v')
    if len(parts) > 2:
        kw_params['distance'] = parts[1]
        kw_params['node'] = parts[2]
    if tag.endswith('-dirty'):
        kw_params['dirty'] = True
    return meta(version, **kw_params)


setup(name='sbp',
      description='Python bindings for Swift Binary Protocol',
      long_description=readme,
      use_scm_version={'root': sbp_root(), 'parse': do_parse},
      parse=do_parse,
      setup_requires=['setuptools_scm'],
      author='Swift Navigation',
      author_email='dev@swiftnav.com',
      url='https://github.com/swift-nav/libsbp',
      classifiers=CLASSIFIERS,
      packages=PACKAGES,
      platforms=PLATFORMS,
      install_requires=INSTALL_REQUIRES,
      tests_require=TEST_REQUIRES,
      use_2to3=False,
      zip_safe=False)
