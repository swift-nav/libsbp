## Specification and Bindings for Swift Binary Protocol

[![Build status][1]][2]

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

* [`docs`](https://github.com/swift-nav/libsbp/tree/HEAD/docs): Protocol documentation and message definitions.
* [`spec`](https://github.com/swift-nav/libsbp/tree/HEAD/spec): Machine readable protocol specification in
  [YAML](http://en.wikipedia.org/wiki/YAML).
* [`generator`](https://github.com/swift-nav/libsbp/tree/HEAD/generator): Simple, template-based generator for
  different languages.
* [`python`](https://github.com/swift-nav/libsbp/tree/HEAD/python): Python client and examples.
* [`c`](https://github.com/swift-nav/libsbp/tree/HEAD/c): C client library and examples.
* [`haskell`](https://github.com/swift-nav/libsbp/tree/HEAD/haskell): Haskell client and examples.
* [`java`](https://github.com/swift-nav/libsbp/tree/HEAD/java): Java client library and examples.
* [`javascript`](https://github.com/swift-nav/libsbp/tree/HEAD/javascript): JavaScript client library and examples.

Except for the `generator`, all of the above are generated and should not be modified directly.

## Building / installing
### Installing from package managers
Some bindings are available on package managers:

* [`python`](https://github.com/swift-nav/libsbp/tree/HEAD/python): available on pip
* [`haskell`](https://github.com/swift-nav/libsbp/tree/HEAD/haskell): available on Hackage
* [`javascript`](https://github.com/swift-nav/libsbp/tree/HEAD/javascript): available on NPM

### Installing from source
You can build one binding at a time or update all at once:

```
make python
```

or

```
make all
```

are both valid. To see a list of all valid targets, run `make help`.

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

[1]: https://travis-ci.org/swift-nav/libsbp.png
[2]: https://travis-ci.org/swift-nav/libsbp
