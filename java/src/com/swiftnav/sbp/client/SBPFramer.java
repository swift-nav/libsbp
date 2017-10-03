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

public class SBPFramer {
    private static final int    PREAMBLE_SIZE = 1;
    private static final byte   PREAMBLE_VALUE = 0x55;

    private static final int    HEADER_SIZE = 5;
    private              byte[] mHeaderByteArray = new byte[HEADER_SIZE];
    private              int    mHeaderByteIndex;
    private              int    mHeaderType;
    private              int    mHeaderSender;
    private              int    mHeaderLen;

    private              byte[] mPayloadByteArray;
    private              int    mPayloadByteIndex;

    private static final int    CRC_SIZE = 2;
    private              byte[] mCrcByteArray = new byte[CRC_SIZE];
    private              int    mCrcByteIndex;

    public int mCrcErrorCount = 0;
    public int mPayloadDecodeErrorCount = 0;

    private enum DecodeState {
        PREAMBLE,
        HEADER,
        PAYLOAD,
        CRC
    }

    private DecodeState mDecodeState = DecodeState.PREAMBLE;

    public SBPFramer() {
        ;
    }

    public SBPMessage parseByte(byte dataByte) {
        SBPMessage msg = null;

        switch (mDecodeState) {
            default:
            case PREAMBLE: {
                // Reset module data for reception of next message.
                mHeaderByteIndex = 0;
                mPayloadByteIndex = 0;
                mPayloadByteArray = null;
                mCrcByteIndex = 0;

                // Check for preamble reception.
                if (dataByte == PREAMBLE_VALUE) {
                    mDecodeState = DecodeState.HEADER;
                }
                break;
            }
            case HEADER: {
                // Append header byte.
                mHeaderByteArray[mHeaderByteIndex] = dataByte;
                mHeaderByteIndex++;

                // Entire header received ?
                if (mHeaderByteIndex >= HEADER_SIZE) {
                    // Unpack header fields.
                    ByteBuffer bb = ByteBuffer.wrap(mHeaderByteArray).order(ByteOrder.LITTLE_ENDIAN);
                    mHeaderType = bb.getShort() & 0xffff;
                    mHeaderSender = bb.getShort() & 0xffff;
                    mHeaderLen = bb.get() & 0xff;
                    
                    // Setup payload storage.
                    mPayloadByteArray = new byte[mHeaderLen];

                    // Move to receiving the payload.
                    // - Check for payload length validity not performed. 'mHeaderLen' is only one byte in size so
                    //   any received payload length value is valid.
                    mDecodeState = DecodeState.PAYLOAD;
                }
                break;
            }
            case PAYLOAD: {
                // Append payload byte.
                mPayloadByteArray[mPayloadByteIndex] = dataByte;
                mPayloadByteIndex++;

                // Entire payload received ?
                if (mPayloadByteIndex >= mHeaderLen) {
                    mDecodeState = DecodeState.CRC;
                }
                break;
            }
            case CRC: {
                // Append CRC byte.
                mCrcByteArray[mCrcByteIndex] = dataByte;
                mCrcByteIndex++;

                // Entire header received ?
                if (mCrcByteIndex >= CRC_SIZE) {
                    // Calculate CRC of received data.
                    int calccrc = CRC16.crc16(mHeaderByteArray);
                    calccrc = CRC16.crc16(mPayloadByteArray, calccrc);

                    // Unpack received CRC.
                    int crc = ByteBuffer.wrap(mCrcByteArray).order(ByteOrder.LITTLE_ENDIAN).getShort() & 0xffff;

                    // CRCs match ?
                    if (crc == calccrc) {
                        msg = new SBPMessage(mHeaderSender, mHeaderType, mPayloadByteArray);
                        try {
                            msg = MessageTable.dispatch(msg);
                        } catch (SBPBinaryException e) {
                            // Error decoding binary payload.
                            msg = null;
                            mPayloadDecodeErrorCount++;
                        }
                    }
                    else
                    {
                        // Mismatch in calculate CRC vs that received.
                        mCrcErrorCount++;
                    }

                    // Reset to perform parsing of next message.
                    mDecodeState = DecodeState.PREAMBLE;
                }
                break;
            }
        }

        return msg;
    }

    /** Encode an SBPMessage */
    public ByteBuffer encodeMessage(SBPMessage msg) {
        byte[] payload = msg.getPayload();
        byte[] binmsg = new byte[PREAMBLE_SIZE + HEADER_SIZE + payload.length + CRC_SIZE];
        ByteBuffer bb = ByteBuffer.wrap(binmsg).order(ByteOrder.LITTLE_ENDIAN);
        bb.put(PREAMBLE_VALUE);
        bb.putShort((short) msg.type);
        bb.putShort((short) msg.sender);
        bb.put((byte)payload.length);
        bb.put(payload);
        int crc = CRC16.crc16(Arrays.copyOfRange(binmsg, 1, payload.length + 6));
        bb.putShort((short) crc);

        return bb;
    }
}
