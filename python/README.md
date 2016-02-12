# SBP Bindings for Python

Python client for Swift Binary Protocol (SBP).

## Requirements

You must have `python`, `pip`, and `pandoc` installed to build the Python library (`pandoc` is only used during the build process).

## Install from pypi

Install package from pypi::

  $ sudo pip install sbp

## Install from source

Install dependencies only::

  $ sudo pip install -r requirements.txt

Install from repo::

  $ sudo python setup.py install

# Usage Examples

## Simple example

Receives SBP messages over a serial port, decodes MSG_BASELINE
messages and prints them out. See [`simple.py`](https://github.com/swift-nav/libsbp/blob/master/python/sbp/client/examples/simple.py).

Run this example with::

  $ python -m sbp.client.examples.simple -p /path/to/serial/port

## Sending SBP messages over UDP

Receives SBP messages over a serial port and sends all incoming
messages to a UDP socket. See [`udp.py`](https://github.com/swift-nav/libsbp/blob/master/python/sbp/client/examples/udp.py).

Run this example with::

  $ python -m sbp.client.examples.udp -s /path/to/serial/port

# Testing

To run the tests and check for coverage::

  $  py.test -v --cov sbp tests/

To run the tests without suppressing stdout output:

  $  py.test -v -s --cov sbp tests/

# License

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.
