#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

try:
  from setuptools import setup, find_packages
except ImportError:
  print('Please install or upgrade setuptools or pip to continue.')
  sys.exit(1)

setup(name='sbp_gen',
      description='Generator for Swift Binary Protocol',
      long_description=open('README.md', 'rb').read().decode('utf8'),
      version='0.10',
      author='Swift Navigation',
      author_email='mookerji@swiftnav.com',
      maintainer='Bhaskar Mookerji',
      maintainer_email='mookerji@swiftnav.com',
      url='https://github.com/swift-nav/libsbp/generator',
      install_requires=[
          'Jinja2',
          'voluptuous'
      ],
      keywords='',
      classifiers=['Intended Audience :: Developers',
                   'Intended Audience :: Science/Research',
                   'Operating System :: POSIX :: Linux',
                   'Operating System :: MacOS :: MacOS X',
                   'Programming Language :: Python',
                   'Topic :: Scientific/Engineering :: Interface Engine/Protocol Translator',
                   'Topic :: Software Development :: Libraries :: Python Modules',
                   'Programming Language :: Python :: 3.8',
                   'Programming Language :: Python :: 3.9',
                   'Programming Language :: Python :: 3.10',
                   'Programming Language :: Python :: 3.11',
                   'Programming Language :: Python :: 3.12',
                   'Programming Language :: Python :: 3.13',
                   'Programming Language :: Python :: 3.14',
                   ],
      packages=find_packages(),
      python_requires='>=3.8',
      zip_safe=False)
