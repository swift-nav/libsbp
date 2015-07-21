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
package com.swiftnav.sbp.client;

import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Arrays;

/** Provide an interface for sending and receiving SBP messages through an
 * SBPDriver.  Implements the details of message framing.
 */
public class SBPHandler {
    private static final byte PREAMBLE = 0x55;

    private static final int PREAMBLE_SIZE = 1;
    private static final int HEADER_SIZE = 5;
    private static final int CRC_SIZE = 2;

    private static final int THREAD_WAIT_TIMEOUT = 1000;

    private SBPDriver driver;
    private HashMap<Integer, LinkedList<SBPCallback>> callbacks;
    private ReceiveThread receiveThread;

    public SBPHandler(SBPDriver driver_) {
        driver = driver_;
        callbacks = new HashMap<>();
    }

    /** Start the listener/dispatch thread */
    public void start() {
        assert(receiveThread == null);
        receiveThread = new ReceiveThread();
        receiveThread.start();
    }

    /** Request to stop the listener/dispatch thread */
    public void stop() {
        if (receiveThread == null)
            return;

        receiveThread.finish();
        try {
            receiveThread.join(THREAD_WAIT_TIMEOUT);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        receiveThread = null;
    }

    private SBPMessage receive() throws IOException {
        /* Wait for a preamble to be received */
        byte[] preamble;
        do {
            preamble = driver.read(PREAMBLE_SIZE);
            if (preamble == null) {
                throw new IOException("SBPDriver read() returned null!");
            }
        } while (preamble[0] != PREAMBLE);

        /* Read the header */
        byte[] header = driver.read(HEADER_SIZE);
        int calccrc = CRC16.crc16(header);
        /* Unpack fields from received header */
        ByteBuffer bb = ByteBuffer.wrap(header).order(ByteOrder.LITTLE_ENDIAN);
        int type = bb.getShort() & 0xffff;
        int sender = bb.getShort() & 0xffff;
        int len = bb.get() & 0xff;

        byte[] payload = driver.read(len);
        calccrc = CRC16.crc16(payload, calccrc);

        int crc = ByteBuffer.wrap(driver.read(CRC_SIZE))
                .order(ByteOrder.LITTLE_ENDIAN).getShort() & 0xffff;
        if (crc != calccrc) {
            System.err.println("CRC error in received SBPMessage");
            return null;
        }

        return new SBPMessage(sender, type, payload);
    }

    /** Send an SBPMessage using the driver */
    public void send(SBPMessage msg) throws IOException {
        byte[] payload = msg.getPayload();
        byte[] binmsg = new byte[PREAMBLE_SIZE + HEADER_SIZE + payload.length + CRC_SIZE];
        ByteBuffer bb = ByteBuffer.wrap(binmsg).order(ByteOrder.LITTLE_ENDIAN);
        bb.put(PREAMBLE);
        bb.putShort((short) msg.type);
        bb.putShort((short) msg.sender);
        bb.put((byte)payload.length);
        bb.put(payload);
        int crc = CRC16.crc16(Arrays.copyOfRange(binmsg, 1, payload.length + 6));
        bb.putShort((short) crc);
        driver.write(bb.array());
    }

    /** Register a message handler for a specific message ID. */
    public void addCallback(Integer id, SBPCallback cb) {
        LinkedList<SBPCallback> cblist;
        if (callbacks.containsKey(id)) {
            cblist = callbacks.get(id);
        } else {
            cblist = new LinkedList<>();
            callbacks.put(id, cblist);
        }
        cblist.add(cb);
    }

    /** Register a message handler for a list of message IDs */
    public void addCallback(Iterable<Integer> ids, SBPCallback cb) {
        for (int id : ids)
            addCallback(id, cb);
    }

    /** Register a message handler for all messages */
    public void addCallback(SBPCallback cb) {
        LinkedList<SBPCallback> cblist;
        if (callbacks.containsKey(null)) {
            cblist = callbacks.get(null);
        } else {
            cblist = new LinkedList<>();
            callbacks.put(null, cblist);
        }
        cblist.add(cb);
    }

    private class ReceiveThread extends Thread {
        private boolean stopFlag = false;

        @Override
        public void run() {
            while (!stopFlag) {
                SBPMessage msg;
                try {
                    msg = receive();
                } catch (IOException e) {
                    System.err.println("SBP Listener thread exiting");
                    break;
                }

                if (msg == null)
                    continue;

                try {
                    msg = MessageTable.dispatch(msg);
                } catch (SBPBinaryException e) {
                    System.err.print("Error decoding binary payload");
                    e.printStackTrace();
                    continue;
                }

                if (callbacks.containsKey(msg.type))
                    for (SBPCallback cb : callbacks.get(msg.type))
                        cb.receiveCallback(msg);
                if (callbacks.containsKey(null))
                    for (SBPCallback cb : callbacks.get(null))
                        cb.receiveCallback(msg);
            }
        }

        void finish() {
            stopFlag = true;
        }
    }
}

