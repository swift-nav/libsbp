#!/usr/bin/env python

from sbp import __version__
from setuptools import setup

classifiers = [
  'Intended Audience :: Developers',
  'Intended Audience :: Science/Research',
  'Operating System :: POSIX :: Linux',
  'Operating System :: MacOS :: MacOS X',
  'Programming Language :: Python',
  'Topic :: Scientific/Engineering :: Interface Engine/Protocol Translator',
  'Topic :: Software Development :: Libraries :: Python Modules',
  'Programming Language :: Python :: 2.7',
]

packages = [
  'sbp',
  'sbp.client',
  'sbp.client.drivers',
  'sbp.client.loggers',
]

platforms = [
  'linux',
  'osx',
  'win32',
]

setup(name='libsbp',
      description='Python bindings for Swift Binary Protocol',
      version=__version__,
      author='Swift Navigation',
      author_email='mookerji@swiftnav.com',
      maintainer='Bhaskar Mookerji',
      maintainer_email='mookerji@swiftnav.com',
      url='https://github.com/swift-nav/libsbp',
      classifiers=classifiers,
      packages=packages,
      platforms=platforms,
      use_2to3=False,
      zip_safe=False)
