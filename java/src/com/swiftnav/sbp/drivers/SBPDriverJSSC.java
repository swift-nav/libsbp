/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 *
 * Based on community contributed code:
 * https://groups.google.com/forum/#!topic/swiftnav-discuss/s0ouH81Lc88
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.drivers;

import com.swiftnav.sbp.client.SBPDriver;

import java.io.IOException;

import jssc.SerialPort;
import jssc.SerialPortException;

/* SBP Driver implementation for serial ports. */
public class SBPDriverJSSC implements SBPDriver {
    public static final int BAUDRATE_DEFAULT = 1000000;
    private SerialPort port;

    public SBPDriverJSSC(String path) throws SerialPortException {
        this(path, BAUDRATE_DEFAULT);
    }

    public SBPDriverJSSC(String path, int baudrate) throws SerialPortException {
        port = new SerialPort(path);
        port.openPort();
        port.setParams(baudrate, 8, 1, 0);
    }

    @Override
    public byte[] read(int n) throws IOException {
        try {
            byte[] ret = port.readBytes(n);
            if (ret.length != n) {
                throw new IOException("Port returned short read!");
            }
            return ret;
        } catch (SerialPortException e) {
            throw new IOException(e);
        }
    }

    @Override
    public void write(byte[] data) throws IOException {
        try {
            port.writeBytes(data);
        } catch (SerialPortException e) {
            throw new IOException(e);
        }
    }
}

