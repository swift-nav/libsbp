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


class JSONLogger(BaseLogger):
    """
    JSONLogger

    The :class:`JSONLogger` logs JSON records.
    """

    def fmt_msg(self, data, **metadata):
        metadata.update(self.tags)
        metadata['data'] = data
        return metadata

    def dump(self, msg, **metadata):
        try:
            data = self.dispatch(msg).to_json_dict()
            return json.dumps(self.fmt_msg(data, **metadata), allow_nan=False)
        except (ValueError, UnicodeDecodeError):
            try:
                warn = "Bad values in JSON encoding for msg_type %d for msg %s" \
                       % (msg.msg_type, msg)
                warnings.warn(warn, RuntimeWarning)
                return json.dumps(self.fmt_msg(msg.to_json_dict(), **metadata))
            except (ValueError, UnicodeDecodeError):
                return None

    def __call__(self, msg, **metadata):
        output = self.dump(msg, **metadata)
        if output:
            self.handle.write(output + "\n")


class JSONBinLogger(BaseLogger):
    """
    JSONBinLogger

    The :class:`JSONLogger` logs JSON records without expanding the fields.
    """

    def fmt_msg(self, data, **metadata):
        metadata.update(self.tags)
        metadata['data'] = data
        return metadata

    def dump(self, msg, **metadata):
        try:
            data = {
                'preamble': msg.preamble,
                'msg_type': msg.msg_type,
                'sender': msg.sender,
                'length': msg.length,
                'payload': base64.standard_b64encode(msg.payload),
                'crc': msg.crc
            }
            return json.dumps(self.fmt_msg(data, **metadata), allow_nan=False)
        except (ValueError, UnicodeDecodeError):
            try:
                warn = "Bad values in JSON encoding for msg_type %d for msg %s" \
                       % (msg.msg_type, msg)
                warnings.warn(warn, RuntimeWarning)
                return json.dumps(self.fmt_msg(msg.to_json_dict(), **metadata))
            except (ValueError, UnicodeDecodeError):
                return None

    def __call__(self, msg, **metadata):
        output = self.dump(msg, **metadata)
        if output:
            self.handle.write(output + "\n")


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

    def next(self):
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
        for line in self.handle:
            try:
                data = json.loads(line)
                item = SBP.from_json_dict(data.pop('data', data))
                msg = self.dispatch(item, line)
                yield (msg, data)
            except (ValueError, UnicodeDecodeError):
                warn = "Bad JSON decoding for line %s" % line
                warnings.warn(warn, RuntimeWarning)
        self.handle.seek(0, 0)
        raise StopIteration
