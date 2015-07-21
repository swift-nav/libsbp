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
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.ByteBuffer;
import java.util.Arrays;

/** SBP Driver implementation for TCP client sockets. */
public class SBPDriverUDP implements SBPDriver {
    static final int RECV_SIZE = 65535;
    private DatagramSocket socket;
    private String server;
    private int port;
    byte[] rxdata;

    public SBPDriverUDP(String server_, int port_) {
        server = server_;
        rxdata = new byte[0];
        port = port_;
    }

    @Override
    public byte[] read(int len) throws IOException {
        synchronized (this) {
            if (socket == null)
                openSocket();
        }

        while (rxdata.length < len) {
            DatagramPacket packet = new DatagramPacket(new byte[RECV_SIZE], RECV_SIZE);
            socket.receive(packet);
            ByteBuffer bb = ByteBuffer.allocate(rxdata.length + packet.getLength());
            bb.put(rxdata);
            bb.put(packet.getData(), 0, packet.getLength());
            rxdata = bb.array();
        }
        byte[] ret = Arrays.copyOf(rxdata, len);
        rxdata = Arrays.copyOfRange(rxdata, len, rxdata.length);
        return ret;
    }

    @Override
    public void write(byte[] data) throws IOException {
        synchronized (this) {
            if (socket == null)
                openSocket();
        }

        DatagramPacket packet = new DatagramPacket(data, data.length);
        socket.send(packet);
    }

    private void openSocket() throws IOException {
        socket = new DatagramSocket();
        socket.connect(InetAddress.getByName(server), port);
        socket.send(new DatagramPacket(new byte[]{0}, 1));
    }
}
