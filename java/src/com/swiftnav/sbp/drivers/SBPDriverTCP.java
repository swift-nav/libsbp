/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
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
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;

/** SBP Driver implementation for UDP client sockets. */
public class SBPDriverTCP implements SBPDriver {
    static final String TAG = "SBPDriverTCP";
    private Socket socket;
    private String server;
    private int port;

    public SBPDriverTCP(String server_, int port_) {
        server = server_;
        port = port_;
    }

    @Override
    public byte[] read(int len) throws IOException {
        byte[] ret = new byte[len];
        int i = 0;

        synchronized (this) {
            if (socket == null)
                openSocket();
        }

        while (i < len) {
            int count = socket.getInputStream().read(ret, i, len - i);
            if (count < 0) {
                throw new IOException("read from broken socket");
            }
            i += count;
        }
        return ret;
    }

    @Override
    public void write(byte[] data) throws IOException {
        synchronized (this) {
            if (socket == null)
                openSocket();
        }

        socket.getOutputStream().write(data);
    }

    private void openSocket() throws IOException {
        socket = new Socket();
        SocketAddress addr = new InetSocketAddress(InetAddress.getByName(server), port);
        socket.connect(addr, port);
    }
}
