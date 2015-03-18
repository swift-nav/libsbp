#!/usr/bin/env python

from sbp import __version__
from setuptools import setup

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

# TODO
INSTALL_REQUIRES = []

with open('README.md') as f:
  readme = f.read()

setup(name='sbp',
      description='Python bindings for Swift Binary Protocol',
      long_description=readme,
      version=__version__,
      author='Swift Navigation',
      author_email='dev@swiftnav.com',
      url='https://github.com/swift-nav/libsbp',
      classifiers=CLASSIFIERS,
      packages=PACKAGES,
      platforms=PLATFORMS,
      install_requires=INSTALL_REQUIRES,
      use_2to3=False,
      zip_safe=False)
