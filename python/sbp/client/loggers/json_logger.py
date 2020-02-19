# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from ...msg import SBP
from ...table import dispatch
from .base_logger import BaseLogger, LogIterator
import base64
import json
import warnings


class JSONLoggerBase(BaseLogger):
    """
    JSONLoggerBase

    The :class:`JSONLoggerBase` base class for JSON loggers.
    """

    def __init__(self, handle, tags={}, dispatcher=None, sort_keys=False):
        BaseLogger.__init__(self, handle, tags, dispatcher)
        self._sort_keys=sort_keys

    def fmt_msg(self, data, **metadata):
        if metadata:
            metadata.update(self.tags)
            metadata['data'] = data
            return metadata

        return data

    def __call__(self, msg, **metadata):
        output = self.dump(msg, **metadata)
        if output:
            self.handle.write(output + "\n")


class JSONLogger(JSONLoggerBase):
    """
    JSONLogger

    The :class:`JSONLogger` logs JSON records.
    """

    def dump(self, msg, **metadata):
        try:
            data = self.dispatch(msg).to_json_dict()
            return json.dumps(self.fmt_msg(data, **metadata),
                              allow_nan=False,
                              sort_keys=self._sort_keys,
                              separators=(',',':'))
        except (ValueError, UnicodeDecodeError):
            try:
                warn = "Bad values in JSON encoding for msg_type %d for msg %s" \
                       % (msg.msg_type, msg)
                warnings.warn(warn, RuntimeWarning)
                return json.dumps(self.fmt_msg(msg.to_json_dict(), **metadata))
            except (ValueError, UnicodeDecodeError):
                return None


class JSONBinLogger(JSONLoggerBase):
    """
    JSONBinLogger

    The :class:`JSONLogger` logs JSON records without expanding the fields.
    """

    def dump(self, msg, **metadata):
        try:
            data = {
                'preamble': msg.preamble,
                'msg_type': msg.msg_type,
                'sender': msg.sender,
                'length': msg.length,
                'payload': base64.standard_b64encode(msg.payload).decode('ascii'),
                'crc': msg.crc
            }
            return json.dumps(self.fmt_msg(data, **metadata),
                              allow_nan=False,
                              sort_keys=self._sort_keys,
                              separators=(',',':'))
        except (ValueError, UnicodeDecodeError):
            try:
                warn = "Bad values in JSON encoding for msg_type %d for msg %s" \
                       % (msg.msg_type, msg)
                warnings.warn(warn, RuntimeWarning)
                return json.dumps(self.fmt_msg(msg.to_json_dict(), **metadata))
            except (ValueError, UnicodeDecodeError):
                return None


class JSONLogIterator(LogIterator):
    """
    JSONLogIterator

    The :class:`JSONLogIterator` is an iterator for reading JSON logs
    of SBP data.

    Parameters
    ----------
    filename : string
      Path to file to read SBP messages from.
    """

    def __init__(self, handle, dispatcher=dispatch, conventional=False):
        super(JSONLogIterator, self).__init__(handle, dispatcher=dispatcher)
        self._broken = False
        self._conventional = conventional

    def breakiter(self):
        """
        Break out of message iteration.
        May be called from another thread when some thread is blocked in next().
        """
        self._broken = True

    def _extract_data(self, line):
        data = json.loads(line)
        if "payload" in data.keys():
            item = SBP.from_json_dict(data)
        else:
            item = SBP.from_json_dict(data.pop('data', data))
        msg = self.dispatch(item, line)
        return (msg, data)

    def _next_conventional(self):
        if self._broken:
            raise StopIteration

        try:
            line = self.handle.readline()

            if not line:
                raise StopIteration

            return self._extract_data(line)
        except (ValueError, UnicodeDecodeError):
            warn = "Bad JSON decoding for line %s" % line
            warnings.warn(warn, RuntimeWarning)
            # Try next line, can lead to RecursionError if source is full of rubbish
            return self._next_conventional()

    def _next_legacy(self):
        for line in self.handle:
            try:
                yield self._extract_data(line)
            except (ValueError, UnicodeDecodeError):
                warn = "Bad JSON decoding for line %s" % line
                warnings.warn(warn, RuntimeWarning)
        self.handle.seek(0, 0)

    def __next__(self):
        """
        Return the next record tuple from log file containing
        JSON-serialized SBP. If an unknown SBP message type is found,
        it'll return the raw SBP. If EOF, throws exception and then
        returns to start of file.

        Returns
        -------
        Tuple(sbp MSG object, {'time':'ISO 8601 time'})
          Second item is for metadata. There used to be multiple fields and
          there could be more in the future.

        Notes
        -----
        In practice it seems like a lot of times JSONLogIterator objects return
        iterators instead of tuples due to weird usage of the class.

        """
        if self._conventional:
            return self._next_conventional()
        else:
            return self._next_legacy()
