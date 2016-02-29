#!/usr/bin/env python

from setuptools import setup
import os
from sbp.version import VERSION

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

PACKAGE_DATA = { 'sbp' : [
  'RELEASE-VERSION',
] }

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
      package_data=PACKAGE_DATA,
      install_requires=INSTALL_REQUIRES,
      use_2to3=False,
      zip_safe=False)
