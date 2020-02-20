# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .base_driver import BaseDriver


class FileDriver(BaseDriver):
    """
    BaseDriver

    The :class:`BaseDriver` class wraps IO sources of SBP messages and provides
    context management.

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
        return_val = self.handle.read(size)
        if not return_val:
            raise IOError
        else:
            return return_val

    def __init__(self, fd):
        super(FileDriver, self).__init__(fd)

    def readline(self):
        return self.handle.readline()
