SBP Bindings for Java
=======================

Java client for Swift Binary Protocol (SBP). Packaging and testing are
mediated through Clojure.

Setup
-----

Install package with Maven::

  <dependency>
    <groupId>org.swiftnav</groupId>
    <artifactId>sbp</artifactId>
    <version>0.1.0</version>
  </dependency>

Usage Examples
--------------

Simple example
~~~~~~~~~~~~~~

Receives SBP messages over a serial port, decodes MSG_BASELINE
messages and prints them out.

Run this example with::

  $ python -m sbp.client.examples.simple -p /path/to/serial/port

Sending SBP messages over UDP
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Receives SBP messages over a serial port and sends all incoming
messages to a UDP socket. See

Run this example with::

  $ python -m sbp.client.examples.udp -s /path/to/serial/port

Testing
--------------

To run the tests and check for coverage::

  $  lein test

License
-------

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.
