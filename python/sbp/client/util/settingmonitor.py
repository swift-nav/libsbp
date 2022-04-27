# Copyright (C) 2017-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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

from sbp.settings import SBP_MSG_SETTINGS_READ_RESP

import time


class SettingMonitor(object):
    """Class to monitor Settings via SBP messages

    Parameters
    ----------
    None

    """

    def __init__(self):
        self.settings = []

    def capture_setting(self, sbp_msg, **metadata):
        """Callback to extract and store setting values from
        SBP_MSG_SETTINGS_READ_RESP

        Messages of any type other than SBP_MSG_SETTINGS_READ_RESP are ignored
        """
        if sbp_msg.msg_type == SBP_MSG_SETTINGS_READ_RESP:
            section, setting, value = sbp_msg.payload.split(b'\0')[:3]
            self.settings.append((section, setting, value))

    def wait_for_setting_value(self, section, setting, value, wait_time=5.0):
        """Function to wait wait_time seconds to see a
        SBP_MSG_SETTINGS_READ_RESP message with a user-specified value
        """
        expire = time.time() + wait_time
        ok = False
        while not ok and time.time() < expire:
            settings = [x for x in self.settings if (x[0], x[1]) == (section, setting)]
            # Check to see if the last setting has the value we want
            if len(settings) > 0:
                ok = settings[-1][2] == value

            time.sleep(0.1)
        return ok

    def clear(self, section=None, setting=None, value=None):
        """Clear settings"""
        match = [all((section is None or x_y_z[0] == section,
                      setting is None or x_y_z[1] == setting,
                      value is None or x_y_z[2] == value)) for x_y_z in self.settings]

        keep = [setting_remove for setting_remove in zip(self.settings,match) if not setting_remove[1]]

        self.settings[:] = [x[0] for x in keep]


if __name__ == "__main__":
    from sbp.client import Handler, Framer
    from sbp.client.drivers.network_drivers import TCPDriver
    from sbp.settings import MsgSettingsWrite, MsgSettingsReadReq
    import argparse

    def print_setting(sbp_msg, **metadata):
        print(sbp_msg)

    def main():
        parser = argparse.ArgumentParser(
            description="Swift Navigation SBP Setting Monitor example.")
        parser.add_argument(
            "-H",
            "--host",
            required=True,
            help="specify the host address.")
        parser.add_argument(
            "-p",
            "--port",
            default=55556,
            help="specify the port to use.")
        args = parser.parse_args()

        monitor = SettingMonitor()

        with TCPDriver(args.host, args.port) as driver:
            with Handler(Framer(driver.read, driver.write, verbose=True)) as link:
                driver.flush()
                time.sleep(2)

                # Capture setting messages
                link.add_callback(monitor.capture_setting,
                                  SBP_MSG_SETTINGS_READ_RESP)

                link.add_callback(print_setting, SBP_MSG_SETTINGS_READ_RESP)

                # Disable spectrum analyzer
                link(MsgSettingsWrite(setting=b'%s\0%s\0%s\0' % (
                    b'system_monitor', b'spectrum_analyzer', b'False')))

                # Request the value of the system_monitor:spectrum_analyzer setting
                link(MsgSettingsReadReq(setting=b'%s\0%s\0' % (
                     b'system_monitor', b'spectrum_analyzer')))

                # Wait up to 5 seconds to see the setting we want
                specan_off = monitor.wait_for_setting_value(
                        b'system_monitor', b'spectrum_analyzer', b'False')

                assert(specan_off == True)
                print("Spectrum analyzer turned off!")

                # Request the value of the system_monitor:spectrum_analyzer setting
                link(MsgSettingsReadReq(setting=b'%s\0%s\0' % (
                     b'system_monitor', b'spectrum_analyzer')))

                # Wait up to 5 seconds to see the setting we (don't) want
                specan_off = monitor.wait_for_setting_value(
                        b'system_monitor', b'spectrum_analyzer', b'True')

                assert(specan_off == False)
                print("Spectrum analyzer still off!")

    main()
