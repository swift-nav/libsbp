package com.swiftnav.sbp.client;

import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class SBPFramer extends SBPIterable implements SBPSender {
    private static final byte PREAMBLE = 0x55;

    private static final int PREAMBLE_SIZE = 1;
    private static final int HEADER_SIZE = 5;
    private static final int CRC_SIZE = 2;

    private SBPDriver driver;

    public SBPFramer(SBPDriver driver_) {
        driver = driver_;
    }

    @Override
    protected SBPMessage getNext() {
        try {
            return receive();
        } catch (IOException e) {
            throw new NoSuchElementException();
        }
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

        SBPMessage msg = new SBPMessage(sender, type, payload);
        try {
            msg = MessageTable.dispatch(msg);
        } catch (SBPBinaryException e) {
            System.err.print("Error decoding binary payload");
            e.printStackTrace();
        }
        return msg;
    }

    /** Send an SBPMessage using the driver */
    public void sendMessage(SBPMessage msg) throws IOException {
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
}
