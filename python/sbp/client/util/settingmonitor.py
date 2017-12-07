# Copyright (C) 2017 Swift Navigation Inc.
# Contact: Swift Navigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
"""
the :mod:`sbp.client.util.settingmonitor` module contains functionality to
monitor SBP_MSG_SETTINGS_READ_RESP messages for desired values
"""

import time

class SettingMonitor(object):
    def __init__(self):
        self.settings = []

    def capture_setting(self, sbp_msg, **metadata):
        section, setting, value = sbp_msg.payload.split('\0')[:3]
        self.settings.append((section,setting,value))

    def wait_for_setting_value(self, section, setting, value, wait_time=5.0):
        expire = time.time() + wait_time
        ok = False
        while not ok and time.time() < expire:
            settings = filter(lambda x: (x[0],x[1]) == (section, setting),
                              self.settings)
            # Check to see if the last setting has the value we want
            if len(settings) > 0:
                ok = settings[-1][2] == value

            time.sleep(0.1)
        return ok

    def clear(self):
        self.settings[:] = []

