## SBP Bindings for Python

Python bindings for Swift Binary Protocol Messages.

```shell
# Install dependencies
pip install -r requirements.txt
python setup.py install

# Install package from pypi
pip install libsbp
```

## Usage

```python
```

## Examples

### Simple example

Receives SBP messages over a serial port, decodes `MSG_BASELINE` messages and
prints them out.

See the [`source code`](sbp/client/examples/simple.py)

Run the example:

```shell
$ python -m sbp.client.examples.simple -p /path/to/serial/port
```

### Sending SBP messages over UDP

Receives SBP messages over a serial port and sends all incoming messages to a
UDP socket.

See the [`source code`](sbp/client/examples/udp.py)

Run the example:

```shell
$ python -m sbp.client.examples.udp -s /path/to/serial/port
```

## LICENSE

Copyright © 2015 Swift Navigation

Distributed under LGPLv3.0.
