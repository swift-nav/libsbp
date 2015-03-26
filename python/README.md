SBP Bindings for Python
=======================

Python client for Swift Binary Protocol (SBP).

Setup
-----

```shell
# Install dependencies only
sudo pip install -r requirements.txt

# Install from repo
sudo pip setup.py install

# Install package from pypi
sudo pip install sbp
```

Usage
-----

## Examples

### Simple example

Receives SBP messages over a serial port, decodes `MSG_BASELINE`
messages and prints them out.

See the [`source code`](sbp/client/examples/simple.py).

Run this example with:

```shell
$ python -m sbp.client.examples.simple -p /path/to/serial/port
```

### Sending SBP messages over UDP

Receives SBP messages over a serial port and sends all incoming
messages to a UDP socket.

See the [`source code`](sbp/client/examples/udp.py).

Run this example with:

```shell
$ python -m sbp.client.examples.udp -s /path/to/serial/port
```

## Testing

```shell
# To run the tests and check for coverage:
py.test -v --cov sbp tests/
```

License
-------

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.
