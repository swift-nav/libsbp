# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

U32_MAX = 0xffffffff


class BaseDriver(object):
    """
    BaseDriver

    The :class:`BaseDriver` class wraps IO sources of SBP messages and provides
    context management.

    Parameters
    ----------
    handle : port
      Stream of bytes to read from and write to.
    """

    def __init__(self, handle):
        self.handle = handle
        self.total_bytes_read = 0
        self.total_bytes_written = 0

    def __enter__(self):
        self.flush()
        return self

    def __exit__(self, *args):
        self.flush()
        self.close()

    def _read(self, size):
        """
        Read Internal implementation.
        Should usually be redefined in inheriting classes.

        Parameters
        ----------
        size : int
          Number of bytes to read.
        """
        return self.handle.read(size)

    def read(self, size):
        """
        Read wrapper.

        Parameters
        ----------
        size : int
          Number of bytes to read.
        """
        bytes_read = self._read(size)
        self.total_bytes_read += len(bytes_read)
        self.total_bytes_read &= U32_MAX
        return bytes_read

    def _write(self, s):
        """
        Write Internal Implementation.
        Should usually be redefined in inheriting classes.

        Parameters
        ----------
        s : bytes
          Bytes to write
        """
        return self.handle.write(s)

    def write(self, s):
        """
        Write wrapper.

        Parameters
        ----------
        s : bytes
          Bytes to write
        """
        return_val = self._write(s)
        self.total_bytes_written += len(s)
        self.total_bytes_written &= U32_MAX
        return return_val

    def bytes_read_since(self, last_total_bytes_read):
        """
        Counts the number of bytes that have been read since
        last_total_bytes_read arg by handling any rollover logic required
        from the total_bytes_read counter.

        Parameters
        ----------
        last_total_bytes_read : int
          byte counter value against which to difference

        Returns
        ----------
        difference between last_total_bytes_read and current count
        of bytes read assuming up to one rollover.
        """

        if (self.total_bytes_read - last_total_bytes_read) >= 0:
            return self.total_bytes_read - last_total_bytes_read
        else:  # assume one rollover only (inherent ambiguity)
            return (self.total_bytes_read + U32_MAX) - last_total_bytes_read

    def flush(self):
        """
        Flush wrapper.
        """
        self.handle.flush()

    def close(self):
        """
        Close wrapper.
        """
        self.handle.close()
