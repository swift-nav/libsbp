SBP Bindings for Python
=======================

Python client for Swift Binary Protocol (SBP). 

Since v2.5 libsbp is compatible with Python 2.7, 3.5 to 3.9. For new projects,
Python 3.7 or newer is recommended.

Setup
-----

You must have ``python`` and ``pip`` installed.

Install dependencies only::

  $ pip install -r requirements.txt

Install from source::

  $ pip install ./python

Install package from PyPI (use ``sudo ...`` to install globally)::

  $ pip install sbp

Installing extras to enable JIT speed-ups
-----------------------------------------

The ``sbp.jit`` package is a mostly source compatible alternative to the
``sbp`` package which includes natively compiled speed-ups, built with the
`Numba`_ library.

.. _Numba: https://numba.pydata.org

These speed-ups are optionally enabled because they are only compatible with a
subset of systems and hardware (typically Linux on x86_64/ARM, macOS on x86_64,
and Windows on x86/x86_64).

To enable these speed-ups the package includes several "extras" that enable
either the JIT (just-in-time) or AOT (ahead-of-time) compiled speed-ups.

The recommend route is to install the AOT "extra" to enable these speed-ups
(use ``sudo ...`` to install globally)::

  $ pip install sbp[aot]

To enable JIT, which will compile the speed-ups when the ``sbp.jit`` package is
imported, install the package from PyPI with the "JIT" extra enabled (this will
pull in Numba, which will in turn require a Python LLVM package)::

  $ pip install sbp[jit]

Or locally from the repository::

  $ pip install ./python[jit]

Setup using a virtual environment
---------------------------------

Setup and activate the ``virtualenv``::

   $ virtualenv .env && source .env/bin/activate

Install ``py.test`` in the virtualenv::

   $ pip install pytest-virtualenv

Install the ``pt.test`` coverage tools::

   $ pip install pytest-cov

Finally, proceed to the standard setup instructions.

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

To run the tests without suppressing stdout output:

  $  py.test -v -s --cov sbp tests/

License
-------

Copyright © 2015 Swift Navigation

Distributed under MIT.

.. _simple.py: https://github.com/swift-nav/libsbp/blob/master/python/sbp/client/examples/simple.py
.. _udp.py: https://github.com/swift-nav/libsbp/blob/master/python/sbp/client/examples/udp.py
