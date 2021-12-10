# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .base_driver import BaseDriver

import datetime
import json
import time


class FileDriver(BaseDriver):
    """
    FileDriver

    The :class:`FileDriver` class wraps file handle IO

    Parameters
    ----------
    fd : File descriptor
      File stream.
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


class PlaybackFileDriver(FileDriver):
    """
    PlaybackFileDriver

    The :class:`PlaybackFileDriver` class for SBP log playback. Main purpose is to delay the
    messages to emulate real data.

    Parameters
    ----------
    fd : File handle
      File containing the playback data.
    """

    def __init__(self, fd):
        super(PlaybackFileDriver, self).__init__(fd)
        self._start_datetime = None
        self._start_timestamp = None

    def _delay(self, line):
        """
        Creates delay between messages based on timestamp metadata. Method records the first
        available timestamp and the real datetime of handling that timestamp. This enables two
        separate timelines; real and play(back). Subsequent calls try to keep these timelines insync
        as tightly as possible by utilising sleep whenever necessary.

        Parameters
        ----------
        size : int
          Number of bytes to read.
        """
        data = json.loads(line)

        if not "time" in data:
            return

        timestamp = datetime.datetime.strptime(data["time"], "%Y-%m-%dT%H:%M:%S.%fZ")

        if self._start_datetime and self._start_timestamp:
            real = datetime.datetime.now() - self._start_datetime
            play = timestamp - self._start_timestamp
            delay = (play - real).total_seconds()

            if delay > 0:
                time.sleep(delay)
        else:
            self._start_datetime = datetime.datetime.now()
            self._start_timestamp = timestamp

    def readline(self):
        """
        Readline wrapper. Delays the return as necessary based on timestamps.
        """
        line = super(PlaybackFileDriver, self).readline()

        self._delay(line)

        return line
