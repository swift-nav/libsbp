libsbp Release Notes
============================

For a detailed index of changes, please see the
[`CHANGELOG.md`](CHANGELOG).

Contents
--------
 * [v0.39](#v0.39)
 * [v0.33](#v0.33)

v0.39 <a name="v0.39"></a>
--------------------------

Bug fixes, minor additions, and stability enhancements since
[v0.33](#v0.33).

#### Specifications

- New external events trigger message.
- The ephemeris message is now included in the list of messages to be
  sent over the radio. The ephemeris' field names have been changed to
  avoid clashing with existing SBP fields (e.g., 'crc' to 'c_rc').

#### Python Library

- Easier to actually materialize a message in place using fields and
  create a new SBP packet to send over the wire. Previously, you
  could only create message objects by deserializing from an existing
  SBP message!
- Robustness improvements for serializing message types to/from JSON.
- Piksi serial link command line tool (`serial_link.py`) now lives in
  [piksi_tools](https://github.com/swift-nav/piksi_tools/).

#### Datasheet Documentation

- More stable datasheet generation when adding new messages ("the
  floats are too dang high!" and automatic versioning from git tags).

v0.33 <a name="v0.33"></a>
--------------------------

First standalone release of libsbp, the native binary messaging
protocol used by Swift Navigation devices. This is a core messaging
dependency for interfacing and integration with the
[Piksi GPS receiver](http://www.swiftnav.com/piksi.html).

#### Specifications

- Centralized and detailed definitions of many, if not all, SBP
  messages output by the Piksi, including messages used only for
  internal development. Previously, some messages were either
  undocumented and created inline by their callers in the firmware or
  the Piksi console.
- Definitions are grouped into files by functionality in a
  machine-readable format, [YAML](http://en.wikipedia.org/wiki/YAML),
  and include some annotated examples and example test cases for
  writers of new language bindings.
- A Python-based generator for our C and Python libraries, as well as
  the Piksi datasheet. This is still a major work-in-progress.

#### C Library

- C header files for SBP message types and library support for parsing
  such messages. This library is now a dependency of the Piksi
  firmware [project](https://github.com/swift-nav/piksi_firmware/).
- Updated Doxygen developer documentation. Available
  [here](https://swift-nav.github.io/libsbp/c/build/docs/html/).

#### Python Library

- Binary parsing for all message types, as well as serial port
  handlers and helpers. This is used by the Piksi
  [console](https://github.com/swift-nav/piksi_tools). Note that
  because messages are now grouped by functionality, some messages
  that were once imported by `import sbp_piksi` are now located in
  different Python submodules. If such changes aren't clear, please
  don't hesitate to ask a question on the
  [forum](https://groups.google.com/forum/#!forum/swiftnav-discuss).
- The serial port client binary for the Piksi is a part of Piksi's
  [tools](https://github.com/swift-nav/piksi_tools).
- The latest stable version is available on
  [PyPi](https://pypi.python.org/pypi/sbp).
- Updated Sphinx developer documentation. Available
  [here](https://swift-nav.github.io/libsbp/python/docs/build/html/).

#### Datasheet Documentation

- A standalone .pdf
  [datasheet](https://github.com/swift-nav/libsbp/raw/v0.33/docs/sbp.pdf)
  describing SBP and message layouts.
