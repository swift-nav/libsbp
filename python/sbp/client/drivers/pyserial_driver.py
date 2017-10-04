# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import threading

from .base_driver import BaseDriver
import serial
import serial.tools.list_ports

from serial.threaded import ReaderThread, Protocol
import time

class Buf(Protocol):
    def __init__(self):
        self.buffer = bytearray()
        self.transport = None
        self.new_data = threading.Event()

    def connection_made(self, transport):
        self.transport = transport

    def connection_lost(self, exc):
        self.transport = None
        super(Buf, self).connection_lost(exc)

    def data_received(self, data):
        """Buffer received data, find TERMINATOR, call handle_packet"""
        # print('pre: prod acq')
        # self.new_data.acquire()
        # print('post: prod acq')
        self.buffer.extend(data)
        self.new_data.set()
        self.new_data.clear()

        # self.new_data.notify()
        # self.new_data.release()


try:
    import termios
    SerialError = termios.error
except ImportError:
    SerialError = None


class PySerialDriver(BaseDriver):
    """
    PySerialDriver

    The :class:`PySerialDriver` class reads SBP messages from a serial port
    using the pyserial driver.  This is mostly redundant, is the Serial object's
    read and write methods can be used directly.

    Parameters
    ----------
    port : string
      URI to port to read SBP messages from. Accepts the following types
      of URLs:
      - rfc2217://<host>:<port>[/<option>[/<option>]]
      - socket://<host>:<port>[/<option>[/<option>]]
      - loop://[<option>[/<option>]]
      and device names, such as /dev/ttyUSB0 (Linux) and COM3 (Windows). See
      http://pyserial.sourceforge.net/pyserial_api.html#urls for more details.
    baud : int
      Baud rate of serial port (defaults to 115200)

    """

    def __init__(self, port, baud=115200, rtscts=False):
        import serial
        try:
            handle = serial.serial_for_url(port)
            handle.baudrate = baud
            handle.timeout = 1
            handle.rtscts = rtscts
            super(PySerialDriver, self).__init__(handle)
            
            self._t = ReaderThread(handle, Buf)
            self._t.start()
            self._transport, self._proto = self._t.connect()
        except (OSError, serial.SerialException) as e:
            print
            print "Error opening serial device '%s':" % port
            print e
            print
            print "The following serial devices were detected:"
            print
            for (name, desc, _) in serial.tools.list_ports.comports():
                if desc[0:4] == "ttyS":
                    continue
                if name == desc:
                    print "\t%s" % name
                else:
                    print "\t%s (%s)" % (name, desc)
            print
            raise SystemExit

    def read(self, size):
        """
        Read wrapper.

        Parameters
        ----------
        size : int
          Number of bytes to read.
        """
        # print('pre: consume acq')
        # self._proto.new_data.acquire()
        # print('post: consume acq')
        while len(self._proto.buffer) < size:
            self._proto.new_data.wait()
            # time.sleep(0.1)
            # self._proto.new_data.wait()
        res = self._proto.buffer[:size]
        del self._proto.buffer[:size]
        return bytes(res)

        # try:
        #     self._proto.new_data.acquire()
        #     return self.handle.read(size)
        # except (OSError, serial.SerialException):
        #     print
        #     print "Piksi disconnected"
        #     print
        #     raise IOError

    def write(self, s):
        """
        Write wrapper.

        Parameters
        ----------
        s : bytes
          Bytes to write
        """
        try:
            # return self.handle.write(s)
            return self._transport.write(s)
        except (OSError, serial.SerialException,
                serial.writeTimeoutError) as e:
            if e == serial.writeTimeoutError:
                print "sbp pyserial_driver: writeTimeoutError"
                return 0
            else:
                print
                print "Piksi disconnected"
                print
                raise IOError

    def __enter__(self):
        self.flush()
        return self

    def __exit__(self, *args):
        try:
            self.flush()
            self.close()
        except (OSError, SerialError, serial.SerialException) as e:
            pass
