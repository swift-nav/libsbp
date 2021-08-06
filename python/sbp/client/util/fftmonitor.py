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
the :mod:`sbp.client.util.fftmonitor` module contains functionality to log
and assemble spectrum analyzer messages into FFT information
"""

from collections import defaultdict
from sbp.client.drivers.network_drivers import TCPDriver
from sbp.client import Handler, Framer
from sbp.gnss import GPSTimeSec
from sbp.piksi import SBP_MSG_SPECAN_DEP
from sbp.piksi import SBP_MSG_SPECAN
import numpy as np

class GPSTimeSecCmp(GPSTimeSec):
    def __init__(self, payload=None, **kwargs):
        super(GPSTimeSecCmp, self).__init__(payload=payload, **kwargs)

    def __cmp__(self, other):
        if other is None:
            return 1
        elif self.wn < other.wn:
            return -1
        elif self.wn > other.wn:
            return 1
        else:
            if self.tow < other.tow:
                return -1
            elif self.tow > other.tow:
                return 1
            else:
                return 0

    def __eq__(self, other):
        if not isinstance(other, GPSTimeSecCmp):
            return False
        return (self.wn == other.wn) and (self.tow == other.tow)

    def __repr__(self):
        return '(wn: {0}, tow: {1})'.format(self.wn, self.tow)

    def __hash__(self):
        return (self.wn, self.tow).__hash__()


class FFTMonitor(object):
    CHANNELS = [1, 2, 3, 4]

    def __init__(self):
        self.mkvalue = lambda: {
            'frequencies': np.array([]),
            'amplitudes': np.array([])}
        self.ffts = {k: [] for k in FFTMonitor.CHANNELS}
        self.incomplete_ffts = {
            ch: defaultdict(self.mkvalue) for ch in FFTMonitor.CHANNELS}
        self.enabled = {i: None for i in FFTMonitor.CHANNELS}

    def get_frequencies(self, sbp_msg):
        ref = sbp_msg.freq_ref
        step = sbp_msg.freq_step
        n = len(sbp_msg.amplitude_value)
        return np.array([ref + step * i for i in range(n)])

    def get_amplitudes(self, sbp_msg):
        ref = sbp_msg.amplitude_ref
        unit = sbp_msg.amplitude_unit
        values = sbp_msg.amplitude_value
        return np.array([ref + unit * value for value in values])

    def capture_fft(self, sbp_msg, **metadata):

        # print "ch:%d, freq_ref: %f, freq_step: %f, amp_ref:%f, num_values:%d, wn:%d, tow:%d" \
        #         % (sbp_msg.channel_tag, sbp_msg.freq_ref, sbp_msg.freq_step, sbp_msg.amplitude_ref, len(sbp_msg.amplitude_value), sbp_msg.t.wn, sbp_msg.t.tow)

        channel = sbp_msg.channel_tag
        if not self.enabled[channel]:
            return

        frequencies = self.get_frequencies(sbp_msg)
        amplitudes = self.get_amplitudes(sbp_msg)
        timestamp = GPSTimeSecCmp(tow=sbp_msg.t.tow, wn=sbp_msg.t.wn)

        self.incomplete_ffts[channel][timestamp]['frequencies'] = np.append(
            self.incomplete_ffts[channel][timestamp]['frequencies'],
            frequencies,
            axis=0)

        self.incomplete_ffts[channel][timestamp]['amplitudes'] = np.append(
            self.incomplete_ffts[channel][timestamp]['amplitudes'],
            amplitudes,
            axis=0)

        if len(self.incomplete_ffts[channel][timestamp]['frequencies']) == 512:
            current_fft = self.incomplete_ffts[channel].pop(timestamp)
            # Clear out any partial messages
            self.incomplete_ffts[channel] = defaultdict(self.mkvalue)

            assert(len(current_fft['frequencies']) ==
                   len(current_fft['amplitudes']))
            self.ffts[channel].append(current_fft)
            #print "FFT Captured for channel %d" % channel

    def _enable(self, en, channel=None):
        if isinstance(channel, int):
            channel = [channel]
        elif channel is None:
            channel = FFTMonitor.CHANNELS
        for ch in channel:
            self.enabled[ch] = en

    def enable_channel(self, channel):
        self.clear_ffts(channel=channel)
        self._enable(True, channel=channel)

    def disable_channel(self, channel):
        self._enable(False, channel=channel)

    def num_ffts(self, channel):
        return len(self.ffts[channel])

    def get_ffts(self, channel):
        return self.ffts[channel][:]

    def clear_ffts(self, channel=None):
        if isinstance(channel, int):
            channel = [channel]
        elif channel is None:
            channel = FFTMonitor.CHANNELS

        for ch in channel:
            self.ffts[ch][:] = []
            self.incomplete_ffts[ch] = defaultdict(self.mkvalue)


def main():
    parser = argparse.ArgumentParser(
        description="Swift Navigation SBP FFT monitor example.")
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
    parser.add_argument(
        "-n",
        "--num-ffts",
        type=int,
        default=5,
        help="specify the number of FFTs to capture.")
    parser.add_argument(
        "-c",
        "--channel",
        type=int,
        default=1,
        help="specify the channel to monitor.")
    parser.add_argument(
        "-o",
        "--output",
        type=str,
        default="fftmonitor",
        help="specify the output filename.")
    args = parser.parse_args()

    monitor = FFTMonitor()
    ch = args.channel
    samples = args.num_ffts

    with TCPDriver(args.host, args.port) as driver:
        with Handler(Framer(driver.read, driver.write, verbose=True)) as link:
            driver.flush()
            link.add_callback(monitor.capture_fft, [SBP_MSG_SPECAN, SBP_MSG_SPECAN_DEP])

            # Capture 5 FFTs from channel 1
            monitor.enable_channel(ch)
            while monitor.num_ffts(ch) < samples:
                time.sleep(1)
            print("Captured %d ffts from channel %d" % (samples, ch))
            ffts = monitor.get_ffts(ch)
            #monitor.disable_channel(ch)

            with open('%s.pickle' % args.output, 'wb') as handle:
                pickle.dump(ffts, handle, protocol=pickle.HIGHEST_PROTOCOL)



if __name__ == "__main__":
    import argparse
    import pickle
    import time
    main()
