:orphan:

SBP Bindings for Python
==============================================

Python client for Swift Binary Protocol (SBP). The Swift Navigation
Binary Protocol (SBP) is a fast, simple, and minimal binary protocol
for communicating with Swift devices. It is the native binary protocol
used by the [Piksi GPS receiver](http://swiftnav.com/piksi.html) to
transmit solutions, observations, status and debugging messages, as
well as receive messages from the host operating system, such as
differential corrections and the almanac.

Setup
------------------

.. code-block::bash

  sudo pip install -r requirements.txt
  sudo pip setup.py install
  sudo pip install sbp

Usage and Examples
------------------

Running Tests
~~~~~~~~~~~~~

.. code-block::bash

  py.test -v --cov sbp tests/

Usage Examples
-------------

.. toctree::
   :maxdepth: 2

   sbp.client.examples


API Reference
-------------

If you are looking for information on a specific function, class or
method, this part of the documentation is for you.

.. toctree::
   :maxdepth: 2

   sbp

Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
