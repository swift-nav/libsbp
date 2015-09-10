## Specification and Bindings for Swift Binary Protocol

The Swift Navigation Binary Protocol (SBP) is a fast, simple, and
minimal binary protocol for communicating with Swift devices. It is
the native binary protocol used by the
[Piksi GPS receiver](http://swiftnav.com/piksi.html) to transmit
solutions, observations, status and debugging messages, as well as
receive messages from the host operating system, such as differential
corrections and the almanac.

This project provides language-agnostic specification and
documentation for messages used with SBP, a compiler for generating
message bindings, and client libraries in a variety of languages. This
repository is organized into the following directory structure:

* [`docs`](docs): Protocol documentation and message definitions.
* [`spec`](spec): Machine readable protocol specification in
  [YAML](http://en.wikipedia.org/wiki/YAML).
* [`generator`](generator): Simple, template-based generator for
  different languages.
* [`python`](python): Python client and examples.
* [`c`](c): C client library and examples.
* [`haskell`](haskell): Haskell client and examples.
* [`java`](java): Java client library and examples.

## SBP Protocol Specification

SBP consists of two pieces: (i) an over-the-wire message framing
format and (ii) structured payload definitions. As of Version 1.0, the
packet consists of a 6-byte binary header section, a variable-sized
payload field, and a 16-bit CRC value. SBP uses the CCITT CRC16
(XMODEM implementation) for error detection.

Please see
[the docs](https://github.com/swift-nav/libsbp/raw/master/docs/sbp.pdf)
for a full description of the packet structure and the message
types. Developer documentatation for the language-specific sbp
libraries is [here](http://swift-nav.github.io/libsbp/).

## LICENSE

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.
