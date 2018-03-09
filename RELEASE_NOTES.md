libsbp Release Notes
============================

For a detailed index of changes, please see the
[`CHANGELOG.md`](CHANGELOG.md).

Contents
--------
 * [v2.3.10](#v2.3.10)
 * [v2.3.9](#v2.3.9)
 * [v2.3.8](#v2.3.8)
 * [v2.3.7](#v2.3.7)
 * [v2.3.6](#v2.3.6)
 * [v2.3.5](#v2.3.5)
 * [v2.3.4](#v2.3.4)
 * [v2.3.3](#v2.3.3)
 * [v2.3.2](#v2.3.2)
 * [v2.3.1](#v2.3.1)
 * [v2.2.15](#v2.2.15)
 * [v2.2.14](#v2.2.14)
 * [v2.2.13](#v2.2.13)
 * [v2.2.12](#v2.2.12)
 * [v2.2.10](#v2.2.10)
 * [v2.2.7](#v2.2.7)
 * [v2.2.6](#v2.2.6)
 * [v2.2.5](#v2.2.5)
 * [v2.2.4](#v2.2.4)
 * [v2.2.2](#v2.2.2)
 * [v2.2.1](#v2.2.1)
 * [v2.2.0](#v2.2.0)
 * [v2.1.8](#v2.1.8)
 * [v2.1.7](#v2.1.7)
 * [v2.1.6](#v2.1.6)
 * [v2.1.5](#v2.1.5)
 * [v2.1.0](#v2.1.0)
 * [v2.0.0](#v2.0.0)
 * [v1.1.1](#v1.1.1)
 * [v1.1.0](#v1.1.0)
 * [v1.0.2](#v1.0.2)
 * [v1.0.1](#v1.0.1)
 * [v0.39](#v0.39)
 * [v0.33](#v0.33)

v2.3.10 <a name="v2.3.10">
--------------------------
* Improve documentation of Settings IO in source code, pdf, and autogen'ed docs

v2.3.9 <a name="v2.3.9">
--------------------------
* Add NetworkUsage message for monitoring data links

v2.3.8 <a name="v2.3.8">
--------------------------
* Python client: Add json bin logger (allow higher perf json logging) 

v2.3.7 <a name="v2.3.7">
--------------------------
* Python client improvements and add a file driver
* Update python client construct version for performance

v2.3.6 <a name="v2.3.6">
--------------------------
* Change scaling on SSR yaw rate message

v2.3.5 <a name="v2.3.5">
--------------------------
* Add MSG\_SBAS\_RAW and precise orbit and clock messages
* Deprecate MSG\_TRACKING\_STATE\_DETAILED
* Implement antenna short flags in heartbeat messages

v2.3.4 <a name="v2.3.4">
--------------------------
* Add attitude and inertial messages to SBP

v2.3.3 <a name="v2.3.3">
--------------------------
* Add fftmonitor code to python client as an API for spectrum analyzer messages
* Add a tcp client example to python client

v2.3.2 <a name="v2.3.2">
--------------------------
* Added MSG\_SETTINGS\_WRITE\_RESP as programmatic way to determine status of setting write

v2.3.1 <a name="v2.3.1">
--------------------------
* Added Glonass code-phase bias message

v2.2.15 <a name="v2.2.15">
--------------------------
* Improve c example code (update baudrate for Piksi Multi and more debug info)
* Update javascript bindings for missing messages

v2.2.14 <a name="v2.2.14">
--------------------------
* update python dependencies

v2.2.13 <a name="v2.2.13">
--------------------------
* Python client improvements and simple.py fixes
* Python formatting updated to pep8
* Python TCPClient autoreconnect

v2.2.12 <a name="v2.2.12">
--------------------------
* Remove MSG\_FCNS\_GLO

v2.2.10 <a name="v2.2.10">
--------------------------
* Haskell SDK improvements: Haskell library now decodes from binary payload
* Fix broken Java build

v2.2.7 <a name="v2.2.7">
--------------------------
* Python dependency fixes
* Haskell: Support lts-8

v2.2.6 <a name="v2.2.6">
--------------------------
* Add IOD to GLONASS Ephemeris Msg
* Add channel ID tag to spectrum analyer message
* Use setuptools\_scm for python versioning

v2.2.5 <a name="v2.2.5">
--------------------------
* Renamed MANIFEST.IN to make it work on linux 

v2.2.4 <a name="v2.2.4">
--------------------------
* Change python dependencies
* Remove not implemented note for estimated accuracy fields

v2.2.2 <a name="v2.2.2">
--------------------------
* Add extern "C" for c++
* New MSG_TRACKING_STATE
* New message

v2.2.1 <a name="v2.2.1">
--------------------------
* Add decimal msg_id to PDF docs
* Fix bug in pyserial driver that could hang and prevent exit
* Fix ephemeris time to be seconds as it exists in all implementation

v2.2.0 <a name="v2.2.0">
--------------------------
* Add Network Status Msg
* Redefine Nanoseconds field of UTC time message as U32 rather than S32
* Redefine Seconds field of UTC message as the floor of the current seconds in minute
* Rename ns field that was a residual to ns_residual
* Add RTCS/CTS option to python serial driver
* Increase Network Driver timeouts for connection and reads
* Add context manager to python client forwarder

v2.1.8 <a name="v2.1.8">
--------------------------
* Add MSG_ALMANAC_GPS (0x70)
* Add MSG_ALMANC_GLO (0x71)

v2.1.7 <a name="v2.1.7">
--------------------------
* python client improvments (threadsafe write)
* Python network driver improvements (verbosity in connection issues)

v2.1.6 <a name="v2.1.6">
--------------------------
* Add MSG_NDB_EVENT

v2.1.5 <a name="v2.1.5">
--------------------------
* Add CDC driver for usb CDC AMC devices

v2.2.4 <a name="v2.2.4">
--------------------------
* Change python dependencies
* Remove not implemented note for estimated accuracy fields

v2.2.2 <a name="v2.2.2">
--------------------------
* Add extern "C" for c++
* New MSG_TRACKING_STATE
* New message

v2.2.1 <a name="v2.2.1">
--------------------------
* Add decimal msg_id to PDF docs
* Fix bug in pyserial driver that could hang and prevent exit
* Fix ephemeris time to be seconds as it exists in all implementation

v2.2.0 <a name="v2.2.0">
--------------------------
* Add Network Status Msg
* Redefine Nanoseconds field of UTC time message as U32 rather than S32
* Redefine Seconds field of UTC message as the floor of the current seconds in minute
* Rename ns field that was a residual to ns_residual
* Add RTCS/CTS option to python serial driver
* Increase Network Driver timeouts for connection and reads
* Add context manager to python client forwarder

v2.1.8 <a name="v2.1.8">
--------------------------
* Add MSG_ALMANAC_GPS (0x70)
* Add MSG_ALMANC_GLO (0x71)

v2.1.7 <a name="v2.1.7">
--------------------------
* python client improvments (threadsafe write)
* Python network driver improvements (verbosity in connection issues)

v2.1.6 <a name="v2.1.6">
--------------------------
* Add MSG_NDB_EVENT

v2.1.5 <a name="v2.1.5">
--------------------------
* Add CDC driver for usb CDC AMC devices

v2.2.4 <a name="v2.2.4">
--------------------------
* Change python dependencies
* Remove not implemented note for estimated accuracy fields

v2.2.2 <a name="v2.2.2">
--------------------------
* Add extern "C" for c++
* New MSG_TRACKING_STATE
* New message

v2.2.1 <a name="v2.2.1">
--------------------------
* Add decimal msg_id to PDF docs
* Fix bug in pyserial driver that could hang and prevent exit
* Fix ephemeris time to be seconds as it exists in all implementation

v2.2.0 <a name="v2.2.0">
--------------------------
* Add Network Status Msg
* Redefine Nanoseconds field of UTC time message as U32 rather than S32
* Redefine Seconds field of UTC message as the floor of the current seconds in minute
* Rename ns field that was a residual to ns_residual
* Add RTCS/CTS option to python serial driver
* Increase Network Driver timeouts for connection and reads
* Add context manager to python client forwarder

v2.1.8 <a name="v2.1.8">
--------------------------
* Add MSG_ALMANAC_GPS (0x70)
* Add MSG_ALMANC_GLO (0x71)

v2.1.7 <a name="v2.1.7">
--------------------------
* python client improvments (threadsafe write)
* Python network driver improvements (verbosity in connection issues)

v2.1.6 <a name="v2.1.6">
--------------------------
* Add MSG_NDB_EVENT

v2.1.5 <a name="v2.1.5">
--------------------------
* Add CDC driver for usb CDC AMC devices
* New flags to the reset message for commanded resets
* Add DGNSS flag to solution messages
* Add IMU raw data messages
* Remove RAIM flag from solution messages

v2.1.0 <a name="v2.1.0">
--------------------------
* Add command and response messages
* Clarify height field is above ellipsoid

v2.0.0 <a name="v2.0.0">
--------------------------
* Deprecated and redefined all navigation messages due to redefinition of the FLAGS field
  * Navigation messages are expected to go out with every solution epoch whether valid or not
* New observation message with Measured Doppler addition, observation flags,  and lock timer
* Deprecation of Piksi V2.3.1 bootloader and flash messages
* Addition of MSG_FWD to allow wrapping of forwardes SBP or other protocol messages
* Addition of UTC Time message
* Addition of DGPS Status Message.  This message will go out with each receipt of base observations.
* Addition of Age of corrections message.  This will go out with every solution epoch to indicate correction age
* Add information fields to reserved word in  MSG_STARTUP definition

v1.1.1 <a name="v1.1.1"></a>
--------------------------
* Javascript: fixed bug with `constructMsg` and added more tests and examples for message construction.

v1.1.0 <a name="v1.1.0"></a>
--------------------------
* Added `MSG_SETTINGS_REGISTER` message
* More improvements to JavaScript to add a `constructMsg` interface (`sbp/construct.js`).

v1.0.2 <a name="v1.0.2"></a>
--------------------------
Minor release: changes JavaScript bindings to simplify constructing
SBP messages.

v1.0.1 <a name="v1.01"></a>
--------------------------
Many changes since the last update to the release notes.  
- New Observation message format (which triggered a major version 
  increment)
- New UART State message format
- Haskell Bindings
- Java Bindings
- Javascript Bindings
- Improvements to python client libraries and iterative interface
  abstraction

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
