## Specification and Bindings for Swift Binary Protocol

The Swift Navigation Binary Protocol (SBP) is the native binary
protocol used by the Piksi to transmit solutions, observations, status
and debugging information as well as to receive information from the
host such as differential corrections and the almanac. This project is
a single source, language-agnostic specification for messages used
with SBP, a compiler for generating message bindings, and clients in a
variety of languages.

## SBP Protocol Specification - Packet Structure

The Swift Binary Protocol is a fast, simple and minimal binary
protocol for sending payloads to, from and between Swift Navigation
devices. It is primarily used to send the binary representation of C
structs with minimal overhead across serial links.

As of Version 1.0, the packet consists of a 6 byte binary header
section, a variable-sized payload field, and a 2 byte binary CRC
value. SBP uses the CCITT CRC16 (XMODEM implementation) for error
detection. It has no error correction and makes no delivery
guarantees.

The full packet structure is as follows:

| Field | Size (Bytes) | Purpose |
| -----|-------- | ----------|
| Preamble | 1 | Denotes the start of frame transmission. For v1.0, always 0x55 |
| Message Type | 2 | ldentifies the payload contents. |
| Sender | 2 | A unique identifier of the sending hardware. For v1.0 on Piksi, set to the 2 least significant bytes of the Piksi serial number. |
| Length (n) |	1 | Length in bytes of the Payload field. |
| Payload | n | Binary data of the message, as identified by Message Type and Length. Usually contains the in-memory binary representation of a C struct (see documentation on individual message types). |
| CRC | 2 | Cyclic Redundancy Check of the packet's binary data from the Message Type up to the end of Payload (does not include the Preamble). |

## Message Types

SBP supports 65536 different message types (most are currently
unused), identified by the `msg_type` field in the header.

See
[the docs](https://github.com/swift-nav/libswiftnav/raw/master/docs/sbp.pdf)
for the preliminary documentation of the official message types. The
official messages include such things as timing and position messages,
but not implementation specific messages such as firmware version.

## Using the SBP Compiler

TODO(Buro)

## Example - Decoding SBP in Python

Here is an example of how to use the libsbp and
[serial_link.py](https://github.com/swift-nav/piksi_firmware/tree/master/scripts)
to decode SBP messages:

```python
import sbp_piksi as sbp
import serial_link
import time

def baseline_callback(data):
  # This function is called every time we receive a BASELINE_NED message

  # First, decode the binary SBP data in "data" into a python object, the sbp
  # module has functions that do this for all the message types defined in the
  # official spec.
  b = sbp.BaselineNED(data)

  # Solution now contains the decoded baseline information and
  # has fields with the same names as in the SBP docs.

  # Print out the N, E, D coordinates of the baseline.
  print "%.4f,%.4f,%.4f" % \
    (b.n * 1e-3, b.e * 1e-3, b.d * 1e-3)


# Open a connection to Piksi on '/dev/ttyUSB0' using the default baud rate.
link = serial_link.SerialLink(port="/dev/tty.usbserial-00002026")

# Add our callback function to handle BASELINE_NED messages.
link.add_callback(sbp.SBP_BASELINE_NED, baseline_callback)

try:
  # Sleep until the user presses Ctrl-C
  while True:
    time.sleep(60)
except:
  # User pressed Ctrl-C, close the connection to Piksi
  link.close()
```

## LICENSE

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.
