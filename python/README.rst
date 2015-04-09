SBP Bindings for Python
=======================

Python client for Swift Binary Protocol (SBP).

Setup
-----

Install dependencies only::

  $ sudo pip install -r requirements.txt

Install from repo::

  $ sudo python setup.py install

Install package from pypi::

  $ sudo pip install sbp

Usage Examples
--------------

Simple example
~~~~~~~~~~~~~~

Receives SBP messages over a serial port, decodes MSG_BASELINE
messages and prints them out. See `simple.py`_ .

Run this example with::

  $ python -m sbp.client.examples.simple -p /path/to/serial/port

Sending SBP messages over UDP
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Receives SBP messages over a serial port and sends all incoming
messages to a UDP socket. See `udp.py`_ .

Run this example with::

  $ python -m sbp.client.examples.udp -s /path/to/serial/port

Testing
--------------

To run the tests and check for coverage::

  $  py.test -v --cov sbp tests/

License
-------

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.

.. _simple.py: https://github.com/swift-nav/libsbp/blob/master/python/sbp/client/examples/simple.py
.. _udp.py: https://github.com/swift-nav/libsbp/blob/master/python/sbp/client/examples/udp.py
