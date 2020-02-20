# Copyright (C) 2016 Swift Navigation Inc.
# Contact: Dennis Zollo <dzollo@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .base_driver import BaseDriver


class CdcDriver(BaseDriver):
    """
    CdcDriver
    The :class:`CdcDriver` class wraps IO sources of SBP messages and provides
    context management.  It is intended for the devices that use the USB Gadget
    CDC ACM drivers and is preferred over PySerial for these devices.

    Parameters
    ----------
    handle : port
      Stream of bytes to read from and write to.
    """

    def _read(self, size):
        """
        Read wrapper.

        Parameters
        ----------
        size : int
          Number of bytes to read.
        """
        try:
            return_val = self.handle.read(size)
            if return_val == '':
                print()
                print("Piksi disconnected")
                print()
                raise IOError
            return return_val
        except OSError:
            print()
            print("Piksi disconnected")
            print()
            raise IOError

    def _write(self, s):
        """
        Write wrapper.

        Parameters
        ----------
        s : bytes
          Bytes to write
        """
        try:
            return self.handle.write(s)
        except OSError:
            print()
            print("Piksi disconnected")
            print()
            raise IOError

    def close(self):
        """
        Close wrapper.
        """
        try:
            self.handle.close()
        except (OSError, IOError):
            pass
