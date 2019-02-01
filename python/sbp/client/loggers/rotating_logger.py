# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from logging.handlers import TimedRotatingFileHandler
from sbp.client.loggers.json_logger import JSONLogger
from sbp.table import dispatch
import six
import logging
import threading
import time


class RotatingFileLogger(JSONLogger):
    """RotatingFileLogger

    The :class:`RotatingFileLogger` JSON logs SBP messages to a rotating
    file handler that's turned over at a specified time interval
    (defaults to 30 minutes). Intended to be a very low-overhead,
    cross-platform rolling logger for field testing.

    Parameters
    ----------
    filename : string
      Path to file to write SBP messages to.
    when : str
      Specifies a type of interval
    interval : int
      Specifies length of interval
    backupCount : int
      Number of backups to keep around
    tags : dict
      Tags to add to SBP message envelope
    dispatcher: dict
      SBP dispatch table

    """

    def __init__(self,
                 filename,
                 when='M',
                 interval=30,
                 backupCount=3,
                 **kwargs):
        super(RotatingFileLogger, self).__init__(None, **kwargs)
        self.handler = TimedRotatingFileHandler(filename, when, interval,
                                                backupCount)
        self.logger = logging.getLogger("Rotating Log")
        self.logger.setLevel(logging.INFO)
        self.logger.addHandler(self.handler)

    def __call__(self, msg, **metadata):
        self.call(msg, **metadata)

    def flush(self):
        self.handler.flush()

    def close(self):
        self.handler.close()

    def call(self, msg, **metadata):
        self.logger.info(self.dump(msg, **metadata))
