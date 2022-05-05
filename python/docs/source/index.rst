:orphan:

SBP Bindings for Python
==============================================

Python client for Swift Binary Protocol (SBP). SBP is a fast, simple,
and minimal binary protocol for communicating with Swift devices. It
is the native binary protocol used by the Piksi GPS receiver to
transmit solutions, observations, status and debugging messages, as
well as receive messages from the host operating system, such as
differential corrections and the almanac.

Please see the message `docs`_ for a full description of the packet
structure and the message types.

.. _docs: https://github.com/swift-nav/libsbp/raw/master/docs/sbp.pdf

Setup
------------------

Install dependencies only::

  $ sudo pip install -r requirements.txt

Install from repo::

  $ sudo pip setup.py install

Install package from pypi::

  $ sudo pip install sbp

Usage Examples
------------------

.. toctree::
   :maxdepth: 2

   sbp.client.examples

Testing
------------------

To run the tests and check for coverage::

  $  py.test -v --cov --cov-report=term-missing sbp tests/

API Reference
-------------

.. toctree::
   :maxdepth: 1

   sbp
   sbp.client
   sbp.constants
   sbp.sbp2json
   sbp.msg
   sbp.table
   sbp.utils

Messages:

.. toctree::
   :maxdepth: 1

   sbp.acquisition
   sbp.bootload
   sbp.ext_events
   sbp.file_io
   sbp.flash
   sbp.gnss
   sbp.imu
   sbp.linux
   sbp.logging
   sbp.mag
   sbp.navigation
   sbp.ndb
   sbp.observation
   sbp.orientation
   sbp.piksi
   sbp.sbas
   sbp.settings
   sbp.solution_meta
   sbp.ssr
   sbp.system
   sbp.tracking
   sbp.user
   sbp.vehicle


Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
