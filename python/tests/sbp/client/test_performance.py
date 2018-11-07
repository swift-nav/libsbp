#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from sbp.client import Handler, Framer, Forwarder
from sbp.client.drivers.file_driver import FileDriver
from sbp.client.loggers.json_logger import JSONLogger, JSONBinLogger
from sbp.msg import SBP
import pytest
import time

PERF_FILE = 'tests/sbp/v2.1.18-hitl.2.sbp'

def log_cb(msg, **kwargs):
    pass

def test_performance_no_callback():
   driver = FileDriver(open(PERF_FILE, 'rb'))
   start_time = time.time()
   try:
       framer = Framer(driver.read, driver.write, True)
       handler = Handler(framer)
       handler.start()
       while handler.is_alive():
           time.sleep(0.001)
   except IOError:
       pass
   elapsed_time = time.time() - start_time
   assert elapsed_time < 1

def test_performance_callback():
   driver = FileDriver(open(PERF_FILE, 'rb'))
   start_time = time.time()
   try:
       framer = Framer(driver.read, driver.write, True)
       handler = Handler(framer)
       handler.add_callback(log_cb)
       handler.start()
       while handler.is_alive():
           time.sleep(0.001)
   except IOError:
       pass
   elapsed_time = time.time() - start_time
   assert elapsed_time < 1

def test_performance_json_logger():
   driver = FileDriver(open(PERF_FILE, 'rb'))
   start_time = time.time()
   try:
       framer = Framer(driver.read, driver.write, True)
       handler = Handler(framer)
       handler.add_callback(log_cb)
       handler.start()
       Forwarder(handler, JSONLogger(open('sbp.ex.json', 'w'))).start()
       while handler.is_alive():
           time.sleep(0.001)
   except IOError:
       pass
   elapsed_time = time.time() - start_time
   assert elapsed_time < 1

def test_performance_json_bin_logger():
   driver = FileDriver(open(PERF_FILE, 'rb'))
   start_time = time.time()
   try:
       framer = Framer(driver.read, driver.write, True)
       handler = Handler(framer)
       handler.add_callback(log_cb)
       handler.start()
       Forwarder(handler, JSONBinLogger(open('sbp.json', 'w'))).start()
       while handler.is_alive():
           time.sleep(.001)
   except IOError:
       pass
   elapsed_time = time.time() - start_time
   assert elapsed_time < 1

def test_performance_json_bin_logger_no_dispatch():
   driver = FileDriver(open(PERF_FILE, 'rb'))
   start_time = time.time()
   try:
       framer = Framer(driver.read, driver.write, True, dispatcher=None)
       handler = Handler(framer)
       handler.add_callback(log_cb)
       handler.start()
       Forwarder(handler, JSONBinLogger(open('sbp.json', 'w'))).start()
       while handler.is_alive():
           time.sleep(.001)
   except IOError:
       pass
   elapsed_time = time.time() - start_time
   assert elapsed_time < 1

if __name__ == "__main__":
  test_performance_no_callback()
