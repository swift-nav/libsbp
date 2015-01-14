#!/usr/bin/env python
# -*- coding: utf-8 -*-

try:
  import sys
  reload(sys).setdefaultencoding("UTF-8")
except:
  pass

try:
  from setuptools import setup, find_packages
except ImportError:
  print 'Please install or upgrade setuptools or pip to continue.'
  sys.exit(1)

setup(name='sbp_gen',
      description='Generator for Swift Binary Protocol',
      long_description=open('README.md').read(),
      version='0.10',
      author='Swift Navigation',
      author_email='mookerji@swiftnav.com',
      maintainer='Bhaskar Mookerji',
      maintainer_email='mookerji@swiftnav.com',
      url='https://github.com/swift-nav/libsbp/generator',
      keywords='',
      classifiers=['Intended Audience :: Developers',
                   'Intended Audience :: Science/Research',
                   'Operating System :: POSIX :: Linux',
                   'Operating System :: MacOS :: MacOS X',
                   'Programming Language :: Python',
                   'Topic :: Scientific/Engineering :: Interface Engine/Protocol Translator',
                   'Topic :: Software Development :: Libraries :: Python Modules',
                   'Programming Language :: Python :: 2.7'
                   ],
      packages=find_packages(),
      platforms="Linux,Windows,Mac",
      py_modules=['libsbp'],
      use_2to3=False,
      zip_safe=False)
